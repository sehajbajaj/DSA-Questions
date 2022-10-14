#### What?
The question wants us to find the maximum capital we can make by doing at most k projects. Since each project has a profit >= 0, therefore we will choose exact k projects because each project will contribute something to our answer. Greedy appraoch would be a better choice here.
​
#### Why Greedy?
The first thing that stops us from using DP is constraints. The things that we would need to memoize are
1 <= k <= 105
0 <= w <= 109
1 <= n <= 105
And these are not feasible constraints to be stored. At max, we can solve upto 106. And here, since we will need to store three of them, we would not be able to.
Then we can see, that in this question, if we just keep on adding the maximum profit we can get from every possible project, we will ultimately have the maximum profit that we can gain. We can note that using priority queue here, would enusre that we choose the most profitable project possible from current w. Priority queue stores the data in decreasing order, so it may be possible that we choose a project, lets say j which has the profit greater that a project, lets say i, such that i<j. But this will not affect our final answer as we have to return the maximum profit. (A+B == B+A, so order doesn't really matter here).
​
#### How?
So, we store the capital of each project with its respective profit into another array of pairs, and sort it based on capitals. This way, we will have the lower capital projects first so that we have something to start from. Now, we make a max heap and while our current capital supports us to choose some projexts, we iterate over all of those projects(that we can choose from with current capital) and keep pushing them in our heap. Next, when we are finished iterating over them, we pick the projext having the maximum profit, we choose that project and add its profit to our current capital.