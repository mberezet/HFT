#High-Frequency Foreign Exchange Currency Trading (Forex HFT)

###Spring 2016

####Members: Graham Gobieski, Kevin Kwan, Ziyi Zhu, Shang Liu

===

##Table of Index
1. Background
2. Design Overview
3. Data and Communication
4. Floating-Point Arithmetic Approximation
5. Graph Storage
6. Bellman-Ford Algorithm
7. Decision-Making
8. Milestones
9. References

##1. Background

High frequency trading is a trading platform that uses computer algorithms and powerful technology tools to perform a large number of trades at very high speeds. Initially, HFT firms operated on a time scale of seconds, but as technology has improved, so has the time required to execute a trade. Firms now compete at the milli- or even microsecond level. This has led to many firms turning to field programmable gate arrays (FPGAs) to achieve greater performance.

Our project focuses on triangular arbitrage opportunities on the foreign exchange market (Forex). The forex market is a decentralized marketplace for trading currency. All trading is conducted over the counter via computer networks between traders around the world. Unlike the stock market, the forex market is open 24 hours for most of the week.

Currencies are priced in relation to each other and quoted in pairs that look like this:
<p align="center">EUR/USD 1.1837</p>
The currency on the left is the base currency and the one on the right is called the cross currency or quote. The base currency is always assumed to be one unit, and the quoted price is what the base currency is equal to in the other currency. In this example, 1 Euro = 1.1837 USD.

Triangular arbitrage takes advantage of pricing inequalities across three different currencies to make a profit. One currency is exchanged for a second, the second for a third currency, and finally the third back to the original currency. For example, if the exchange rates for the following currency pairs were:
<p align="center">EUR/USD 1.1837</p>
<p align="center">EUR/GBP 0.7231</p>
<p align="center">GBP/USD 1.6388</p>
A trader could use 11,847 USD to buy 10,000 Euros.  Those Euros could be sold for 7231 British Pounds, which could then be sold for 11,850 USD, netting a profit of 13 USD.

===

##2. Design Overview
####Figure 2.1: Design Overview

![image](design_overview.jpeg =350x)



===

##3. Data and Communication

===

##4. Floating-Point Arithmetic Approximation

===

##5. Graph Storage

===

##6. Bellman-Ford Algorithm
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
####Figure 6.1: Bellman-Ford on FPGA

![image](bellman_ford.png =800x)

####Algorithm 6.2: Comparator

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

##7. Decision-Making

Our 

===

##8. Milestones


===

##9. References

