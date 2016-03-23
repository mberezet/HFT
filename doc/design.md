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

===

##2. Design Overview
####Figure 2.1: Design Overview

![image](design_overview.png =400x)


===

##3. Data and Communication
###3.1 Raw Data
We will use historical exchange-rate time-series data downloaded from the internet. The website [HistData](http://www.histdata.com/download-free-forex-data/?/metatrader/1-minute-bar-quotes) provides the data for sixty-six Forex pairs broken into yearly chunks. The pairs include:
####Figure 3.1 Forex Pairs 
![image](forexpairs.png =600x)

The data arrives as a CSV file with the following format. We will use the closing rate in our simulations.

####Figure 3.2 Sample Forex Data 
![image](forexsample.png =600x)

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

===

##7. Milestones


===

##8. References

