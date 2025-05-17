For this problem the main problem I had to solve after writing up som sudo code is what can I use from the previous MST problem. To solve this I ended up making a .h file so that i could reuse a few of those functions if a similar siuation came up. 

From here I had to piece together how to impliment Kruskal and Prims algorithms. This was a bit difficult as they both create the same grapgh but they go about it in different ways. This meant figuring out how to break down each algorithm and creating helper functions to clean up my code a bit and make it easier to debug in the future. 

Kruskal's algorithm was the one I really made the helper functions for. This one had a lot of moving pieces to account for when it came dealing with the unions. Because I was not as familiar with what I was doing I had to watch videos to understand that the unionset / find functions help alot to simplify my code. Once I figured out how to get it working it did solidify my decision that it should some what work. 

prims algorithm way handled in much of the same way but there was not as much of a problem with this one due to making a simpliler verison of it in the previous problem.

From here The compareMSTEdgeOrders Function was born in order to compare both of the outputs that the prims and kruskals algoithm had. This is where I implimented the use of my problem 1 helper functions to visualise the process. 

Many of the functions in this solution utilize arrays which are made to hold the edges. if you see 100 around that was justa  random value I had used to determine the max verticies they can hold. 

This program is useful in showing the algorithmic difference in Kruskal and prim. It also helps to demonstrate that they have the same out come despite the difference. This is also useful in providing more helper functions to possibly use in later algorithms. On a broader level it is also useful in seeing how graph representations interact with different MST's algorithms.

This program could also be a good use in testing. Due to it comparing the output of different graphs it can be used to determine preformance of different MST algorithms outside of just these two included. along the same line it visualizes grapgh which is good in comparisons to get a size by side view of possible errors or differences. 