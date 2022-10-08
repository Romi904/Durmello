
 #include <iostream>

class Node
{
    public:
    Node * lchild;
    Node * rchild;
    int data;
    int height;
};

class AVL
{
    Node *root;
public:
    AVL()
    {
        root = NULL;
    }
};


int nodeHeight(Node *p)
{
    int hl=0;
    int hr=0;
    
    hl = (p && p->lchild)? p->lchild->height+1 :0;
    hr = (p && p->rchild)? p->rchild->height+1 :0;
    
    return hl>hr ? hl+1 : hr+1;
    
}


int balanceFactor(Node *p)
{
    int hl=0;
    int hr=0;
    
    hl = (p && p->lchild)? p->lchild->height+1 :0;
    hr = (p && p->rchild)? p->rchild->height+1 :0;
    
    return hl-hr;
    
}

Node * LLrotation(Node *p)
{
    Node *pl;
    Node *plr;
    
    pl = p->lchild;
    plr= pl->rchild;
    
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    
   /* if(root == p)
    {
        root=pl;
    }
    */
    return pl;
}
Node * LRrotation(Node *p)
{
    Node *pl;
    Node *plr;
    
    pl = p->lchild;
    plr= pl->rchild;
    
    pl->lchild = plr->rchild;
    p->rchild
    
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    
   /* if(root == p)
    {
        root=pl;
    }
    */
    return pl;
}



Node * create(Node *p,int key)
{
    Node *t=NULL;
    if(p==NULL)
    {
        t =new Node;
        t->data = key;
        t->lchild=NULL;
        t->rchild=NULL;
        t->height=1;
        return  t;
    }
    
    else if (p->data > key)
    {
        p->lchild = create(p->lchild, key);
    }
    else
    {
        p->rchild = create(p->rchild, key);
    }
    
    p->height = nodeHeight(p);
    
    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
    {
        return LLrotation(p);
    }
    return p;
}






 int main()
 {
    
    return 0;
 }
