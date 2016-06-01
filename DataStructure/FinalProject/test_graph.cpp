/**
 * adjacency lists
 * List of Undirected Graph -> ListUDG
 *
 * @author 朱立宇
 * @date 2016/05/30
 */
class Graph {
private:
    /* data */
public:
    Graph (arguments);
    virtual ~Graph ();

};

#define MAX 100
// 邻接表
class ListUDG
{
    private:
        class ENode{
            public:
                int ivex;           // 该边所指向的顶点的位置
                ENode *nextEdge;    // 指向下一条弧的指针
        };
        class VNode{
            public:
                int data;          // 顶点信息
                ENode *firstEdge;   // 指向第一条依附该顶点的弧
        };

    private: // 私有成员
        int mVexNum;             // 图的顶点的数目
        int mEdgNum;             // 图的边的数目
        VNode mVexs[MAX];
        Deque<VNode> mVexs;

    public:
        // 创建邻接表对应的图(自己输入)
        ListUDG();
        // 创建邻接表对应的图(用已提供的数据)
        ListUDG(char vexs[], int vlen, char edges[][2], int elen);
        ~ListUDG();

        // 打印邻接表图
        void print();

    private:
        // 读取一个输入字符
        char readChar();
        // 返回ch的位置
        int getPosition(char ch);
        // 将node节点链接到list的最后
        void linkLast(ENode *list, ENode *node);
};
