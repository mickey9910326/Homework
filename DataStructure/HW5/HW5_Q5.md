## HW5_Q5

##### The Question

Implement an algorithm to find the k-th to last element of a singly listed list, and analyze the complexity of your implementation.

##### The Code

``` c++

node* find_to_the_last(int k){
    node* cur_node = head_node;
    node* pre_node;
    while (cur_node->next()!= NULL ) {
        cur_node = cur_node->next();
    }
    pre_node = cur_node;
    for (int i = 1; i < k; i++) {
        cur_node = head_node;
        while (cur_node->next() != pre_node ) {
            cur_node = cur_node->next();
        }
        pre_node = cur_node;
    }
    return cur_node;
}

```

複雜度 =
```
2+L*2+1+[(L-1)*2+3]+[(L-2)*2+3]+[(L-3)*2+3]+...+[(L-K+1)*2+3]+1
=4 + (2*L*K) + (3*K) + (k+K^2)
=K^2 + (2L+4)K + 4
```
