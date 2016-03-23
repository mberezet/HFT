#High-Frequency Foreign Exchange Currency Trading (Forex HFT)

###Spring 2016

####Members: Graham Gobieski, Kevin Kwan, Ziyi Zhu, Shang Liu

===

##Table of Index
1. Background
2. Design Overview
3. Data and Communication
	- 3.1 Raw Data
	- 3.2 Preprocesing and Floating-Point Approximation
		- 3.2.1 Logarithm
		- 3.2.2 Rounding
	- 3.3 Communication
4. Graph Storage
5. Bellman-Ford Algorithm
6. Decision-Making
7. Milestones
8. References

##1. Background

High frequency trading is a trading platform that uses computer algorithms and powerful technology tools to perform a large number of trades at very high speeds. Initially, HFT firms operated on a time scale of seconds, but as technology has improved, so has the time required to execute a trade. Firms now compete at the milli- or even microsecond level. This has led to many firms turning to field programmable gate arrays (FPGAs) to achieve greater performance.

Our project focuses on triangular arbitrage opportunities on the foreign exchange market (Forex). The Forex market is a decentralized marketplace for trading currency. All trading is conducted over the counter via computer networks between traders around the world. Unlike the stock market, the Forex market is open 24 hours for most of the week.

Currencies are priced in relation to each other and quoted in pairs that look like this: `EUR/USD 1.1837`. The currency on the left is the base currency and the one on the right is called the cross currency or quote. The base currency is always assumed to be one unit, and the quoted price is what the base currency is equal to in the other currency. In this example, `1 Euro = 1.1837 USD.`

Triangular arbitrage takes advantage of pricing inequalities across three or more different currencies to make a profit. In a three currency situation, one currency is exchanged for a second, the second for a third currency, and finally the third back to the original currency. For example, if the exchange rates for the following currency pairs were `EUR/USD 1.1837`, `EUR/GBP 0.7231`, and `GBP/USD 1.6388` a  trader could use 11,847 USD to buy 10,000 Euros.  Those Euros could be sold for 7231 British Pounds, which could then be sold for 11,850 USD, netting a profit of 13 USD. Unfortunately, acting on these price inefficiencies quickly corrects them, meaning traders must be ready to act immediately when an arbitrage opportunity occurs.

Our group hopes to implement a Forex arbitrage calculator on an FPGA using a parallelized Bellman-Ford algorithm. We believe this will be fast enough to detect and act on arbitrage opportunities in near real time.


===

##2. Design Overview
####Figure 2.1: Design Overview

![image](design_overview.png =400x)

To find arbitrage opportunities, we will use the Bellman-Ford algorithm with edge weights transformed such that
<p align="center">w’= ln(w)</p>
We are looking for graph cycles where the product of edge weights is greater than 1
<p align="center">w<sub>1</sub> * w<sub>2</sub> * w<sub>3</sub> * … * w<sub>n</sub> > 1</p>
Taking the log of both sides results in
<p align="center">log(w<sub>1</sub>) + log(w<sub>2</sub>) + log(w<sub>3</sub>) + … + log(w<sub>n</sub>) > 0</p>
Then we take the negative log, resulting in a sign flip
<p align="center">log(w<sub>1</sub>) + log(w<sub>2</sub>) + log(w<sub>3</sub>) + … + log(w<sub>n</sub>) < 0</p>
Now we are looking for any negative cycles that appear. This is easily done with the Bellman-Ford algorithm, which detects negative cycles (see Algorithm 6.1).  

===

##3. Data and Communication
###3.1 Raw Data
We will use historical exchange-rate time-series data downloaded from the internet. The website [HistData](http://www.histdata.com/download-free-Forex-data/?/metatrader/1-minute-bar-quotes) provides the data for sixty-six Forex pairs broken into yearly chunks. The pairs include:
####Figure 3.1 Forex Pairs 
![image](Forexpairs.png =600x)

The data arrives as a CSV file with the following format. We will use the closing rate in our simulations.

####Figure 3.2 Sample Forex Data 
![image](Forexsample.png =600x)

###3.2 Preprocesing and Floating-Point Approximation
Unfortunately, floating-point arithmetic on the FPGA is not a trivial task and may require a custom implementation of various operations. As a result, we have decided to utilize the floating-point arithmetic resources of the AMD chip onboard the FPGA. As such, we propose a two-step process that manipulates the data in such a way where only integers are streamed to the FPGA. This preprocessing operation is described below:
####3.2.1 Logarithm
As part of the algorithm to detect arbitrage the logarithm of rate is required so that negative-weight cycles are possible (please see seciont 5 for more discussion on the algorithm). We will use the logarithm mechanism on the AMD chip to calculate the logarithm of each rate.
####3.2.2 Rounding
Once the logarithm has been taken we will convert the resulting floating point to an integer by multiplying by a sufficiently large factor of 10 (the greater the factor the higher the precision) and then throw-away the remaining decimal. In this way we will be left with large integers that can be streamed and operated on in the FPGA efficiently.
###3.3 Communication
After preprocessing we will stream the data via the Amba bus to the FPGA using a custom memory-mappied I/O device driver like we did Lab 3. The integers that we will stream will be fixed at 16 bits, and we hope to stream as fast as possible with minimum delay so that we can effectively simulate reality. Initially, the data will be wholly historical, but if time permits we hope to stream live data to the FPGA.

===

##4. Graph Storage

===

##5. Bellman-Ford Algorithm

####Algorithm 6.1: Standard Bellman-Ford
- Let *G(V, E)* be a graph with vertices, *V*, and edges, *E*.
- Let *w(x)* denote the weight of vertex *x*.
- Let *w(i, j)* denote the weight of the edge from source vertex *i* to destination vertex *j*.
- Let *p(j)* denote the predecessor of vertex *j*.
 
```
for each vertex x in V do
	if x is source then
		w(x) = 0
	else
		w(x) = INFINITY
		p(x) = NULL
	end if
end for

for i = 1 to v - 1 do
	for each edge(i, j) in E do
		if w(i) + w(i, j) < w(j) then //Relaxation
			w(j) = w(i) + w(i, j)
			p(j) = i
		end if
	end for
end for

for each edge(i, j) in E do
	if w(j) > w(i) + w(i, j) then
		//Found Negative-Weight Cycle
	end if
end for
```
####Figure 5.1: Bellman-Ford on FPGA

![image](bellman_ford.png =800x)

####Algorithm 5.2: Comparator

- Let e_k denote the edge (k = 0, 1)
- Let j_k denote the destination vertex of the edge (k = 0, 1)
- Let w_k denote the update value (w(i)+w(i,j)) of the edge (k = 0, 1)
- Let u_k denote the update signal of the edge (k = 0, 1)

```
if u_0 = u_1 = 1 then
	if j_0 = j_1 then //Same destination vertex
		if w_0 < w_1 then
			return e_0
		else 
			return e_1
		end if
	else
		if j_0 < j_1 then
			return e_0
		else
			return e_1
		end if
	end if
else if u_0 != u_1 then
	if u_0 = 1 then
		return e_0
	else
		return e_1
	end if
else
	return e_0
	
```


===

##6. Decision-Making
When a negative cycle is detected by the Bellman-Ford algorithm outlined in the previous sections, we will trace back through the path of the cycles, determine the order of trades required and send a signal to execute these trades. While we could include our trades in further simulation we have decided to focus on cycle detection and as such we do not plan, at the moment to have these tradfe effect future rates.

===

##7. Milestones


===

##8. References

