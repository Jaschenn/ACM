## Steps to developing a usable algorithm
* Modal the problem
* Find an algorithm to solve it
* Fast enough? Fits in memory?
* If not , figure out why.
* Find a way to address the problem
* Iterate until satisfied
## dynamic connectivity
> 可以应用在共同好友上，查找两个人是否有间接关系？

### Question

![Snipaste_2019-01-18_22-21-33.png](https://i.loli.net/2019/01/18/5c41e1040fd46.png)

### Model
本质上来说，这是一个图的内容。需要引入联通分量，每一个连通分量就是一个子集，包含了所有的直接连接和间接连接的objects。
那么执行union操作就是将包含两个object的对象的子集执行union合并操作。
