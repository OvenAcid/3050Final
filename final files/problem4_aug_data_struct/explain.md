

problem 4 I choose to impliment sturcts to make accessing differnt variables easier in the ling run. I remembered implimenting them this way from a previous class when we covered lists so that is why I did it in 3 separate structs.

From here I made helper functions that easily access information in the stucts like get size or see if the list is empty. Each objective typically has two or more functions to go with it to help with the ease of implimentation. This some of these functions were also made for ease of use like print list and free list.

Much of my implemataion decisions for this problem were based off of previous implimentations I have made for a list.

Merge sort however had the same thought process behind it. I knew it needed multiple moving parts so I split them up and combined what I could for botht he decending and accending versions. for each step in the process I made a new function then put it all together in to two distict calling functions where the user just needs to give access to the list address.

many of the problems i was facing come in the form of syntax and logic. The logic part mainly showed up in having to rewrite my sudo code especially for merge sort becuase I kinda forgot how to merge it back together. One area I did have some trouble in is figuring out how to find the split. But here I had one pointer moving faster than the other so when it reached the end the other was at the middle. I did this by having the fast pointer skip every other node so it reached the tail quicker.

The utility of this function is that different components can be used for different things. All together this can be used in any capacity that an unordered or ordered list can be implimented. However the utility extends beyond just this problem. Things like printing a list or even the merge sort fucntion can be applied in other scopes. 

Thgis is also useful because it allows for more dynamic appliations. Becuase of the modular way that I implemented it, if anymore information were needed it could just be added to the struct and expand further to fit other situations. 

Lastly it is a good utility for showcasing how ADT's can be used in different applications. it is also a good learning tool to how to build in blocks rather than all in one functions. 



