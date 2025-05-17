
problem 1 is made to be a basic mst that is able to get updated. I made structs for both the edges and the graph for easy access in future functions.

After that I made create edge as a helper function in order to establish each edge within the add edge and add undirected edge functions. I made this decision in order to accomodate each way that a vertex would be added on to a graph. they also are made with directionality in mind so the user can choose if it has a specific direction or if it can go both ways.

Initgraph was made keeping in mind ease of use when it comes to making new graphs and edges within  the problem. UpdateMST made with prims algorithm in mind. This is shown in the way it searches for the edge with the smallest weight when connecting the new vertex to an mst. it also checks to make sure that each edge has an edge that it connects to or it will not be added to the graph. 

print graph was made to have an easier time viewing the result.

the main function is the main way to showcase if each function worked there is no specific reason of its order. Most of the decisions made came from figuring out how to make my sudo code work in real life. I laid out all my functions first then discovered what would be needed and expanded in to smaller functions as I went further into solving the problem.

The utility of this program is that it shows a simple version of prims algorithm. This can be used to help students learn a concept first them use that knowledge to help build the full algorithm later on like I did in other problems. It also is useful in leanrning how MST's function especially when they need to be dynamic and not static. Also it is useful for incremental changes which don't happen all at once. 

The utility of the algorithm its self can be useful in things like network design or other dynamic solutions. Here if new devices need to be added update mst would be helpful so that the whole graph does not need to be reimplimented. For other dynamic applications the update can be useful when ever a node or edge is removed or added and the graph needs to be up to date. in this case an edge or node might be added or removed which could chnage how other applicaitons relying on this graph function. 