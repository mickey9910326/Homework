## HW4_Q5

##### The Question  

How to delete the first node of a singly list ? Assume a list L with length m.

##### My Answer

``` c++
void delete_node(int node_num) { //node_num = m
    /**
     * TODO
     * @var cur_node 存放當前節點
     * @var node_num 愈刪除之節點編號(1開頭)
     * cur_node = head_node
     * @var i = 1 計數用
     * 當 (i != m-1) 且 (cur_node->next != NULL)
     * cur_node 不斷往下個節點走
     * 將cur_node->next (愈刪除之節點)放入 tmp_node
     * 連結 cur_node 與 tmp_node->next
     * 刪除 tmp_node
     *
     * EXCAPTION
     * 1.node_num <= 0 處理：跳出函式
     * 2.node_num >  list長度L
     * 3.node_num =  1 處理：tmp = head, head = head->next
     * 4.node_num =  1 且 節點數只有1 處理：同上，head = head->next (= NULL)
     */

    if (node_num <=0 ) {
        cout << "m <=0" << endl;
        return;
    }
    if (node_num ==1 ) {
        node* tmp_node = head_node;
        head_node = head_node->next();
        delete tmp_node;
        return;
    }
    node* cur_node = head_node;
    int i = 1;
    while(cur_node->next()!=NULL && i !=node_num-1 ){
        cur_node = cur_node->next();
        i++;
    }
    if (cur_node->next()==NULL && i != node_num-1 ) {
        cout << "Wrong input, m > list long L" << endl;
        return;
    }
    node* tmp_node = cur_node->next();
    cur_node->next(cur_node->next()->next());
    delete tmp_node;
}
```
