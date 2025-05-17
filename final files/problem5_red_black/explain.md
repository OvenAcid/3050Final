problem five covered bottle neck spanning trees. After reading a bit about this topic I decided to structure it like some of the other mst problems in this Lab. 

For the inital structure I wanted to format it in a way that would act similar to a tuple when it is all strung together.This helps to access each node and gives a good way to sort and maipulate the mst.

This is also kind of based on the kruskals algorithm so I set up a union find between two different funcitons find and union set. This allows nodes and edges to be connected if they are not already in the graph. This is where it stops the grapgh from becoming fully connected. 

the compare function is just to be used in q sort.

The bottleneck spanning tree utilises all of the previous functions in order to be executed in the least complicated way possible. there are comments through out the code but qsort sorts the list by weight first in order to find the lowest number edge to start with. this is wher ethe kruskals algorithm took influence. 

The union find function is then initalised for the amount of edges that are present at before the mst is created. this is so I had a base to work off of.  from here the program cycles through the edges until the mst is complete and then gets rid of the parent array as it is no longer needed. also to account for disconnected grapghs I added the last statement in the function 

the main function is how I tested each fucntion. since i built this with tuples in mind that is how I made the inital graph. I made edge count dynamic because if i altered it to test different things I wanted to have to chnage the least amount of code to still be functionable.

in the end it is printed out just to make it easier to see the result.

The overall utility of this problem is that it can be used in various settings. in education, it is a great way to see how kruskal algoritms can be applied in different areas. This also a good way to see more applications of greedy algorithms and cycle detection.

For more practical uses it can be used to find routes with the lowest shipping cost or even to find the shortest distance that takes the least amount of time. Lastly it could be used in networking to test the connection between differnt links. This can help to see improvement s that might need to be made in the future.