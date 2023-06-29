#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag TypeTag;
typedef struct ChildNodes ChildNodes;
typedef union NodeValue NodeValue;
typedef struct Node Node;

enum TypeTag {
    // operation node types
    ADD,
    MUL,
    SUB,
    DIV,
    FIB,
    // leaf nodes (number values)
    INT
};

struct ChildNodes {
    Node *left;
    Node *right;
};

union NodeValue {
    ChildNodes childs;
    int int_variable;
};

struct Node {
    TypeTag type;
    NodeValue value;
};

Node *makeOperationNode(Node *left, Node *right, TypeTag type){
    Node *node = (Node *) malloc(sizeof(Node));
    node->value.childs.left = left;
    node->value.childs.right = right;
    node->type = type;

    return node;
};

Node *makeAddNode(Node *l, Node *r){
    return makeOperationNode(l, r, ADD);
}

Node *makeSubNode(Node *l, Node *r){
    return makeOperationNode(l, r, SUB);
}

Node *makeMulNode(Node *l, Node *r){
    return makeOperationNode(l, r, MUL);
}

Node *makeDivNode(Node *l, Node *r){
    return makeOperationNode(l, r, DIV);
}

Node *makeFibNode(Node *l, Node *r){
    return makeOperationNode(l, r, FIB);
}

typedef Node * (*node_maker)(Node *, Node *);
node_maker makeFunc(TypeTag type) {
    switch (type)
    {
        case ADD: return makeAddNode; break;
        case SUB: return makeSubNode; break;
        case MUL: return makeMulNode; break;
        case DIV: return makeDivNode; break;
        case FIB: return makeFibNode; break;
        default: 
            printf("This node type does not exist!\n");
            exit(1);
            break;
    }
};

Node *makeIntegerNode(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value.int_variable = value;
    node->type = INT;

    return node;
}

int fibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i=2; i <= n; i++) 
        fib[i] = fib[i-1] + fib[i-2];
    
    return fib[n];
}

int calc(Node *node) {
    switch (node->type)
    {
        case ADD:
            return calc(node->value.childs.left) + calc(node->value.childs.right);
            break;
        case SUB:
            return calc(node->value.childs.left) - calc(node->value.childs.right);
            break;
        case MUL:
            return calc(node->value.childs.left) * calc(node->value.childs.right);
            break;
        case DIV:
            return calc(node->value.childs.left) / calc(node->value.childs.right);
            break;
        case FIB:
            return fibonacci(calc(node->value.childs.left));
            break;
        case INT:
            return node->value.int_variable;
            break;        
        default:
            printf("This node type does not exist!\n");
            exit(1);
            break;
    }
}

void free_nodes(Node *root){
    if (root->type >= ADD && root->type < FIB) {
        free_nodes(root->value.childs.left);
        free_nodes(root->value.childs.right);
    }

    if (root->type == FIB) 
        free_nodes(root->value.childs.left);

    free(root);
}


int main(void) {
    Node *node_6 = makeIntegerNode(6);
    Node *node_5 = makeIntegerNode(5);
    Node *node_4 = makeIntegerNode(4);
    Node *node_10 = makeIntegerNode(10);
    
    Node *add = (*makeFunc(ADD))(node_10, node_6);
    Node *mul = (*makeFunc(MUL))(node_5, node_4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fib = (*makeFunc(FIB))(sub, NULL);
    // Node *div = (*makeFunc(DIV))(sub, node_4);

    printf("add: %d\n", calc(add));
    printf("mul: %d\n", calc(mul));
    printf("sub: %d\n", calc(sub));
    printf("fib: %d\n", calc(fib));
    // printf("div: %d\n", calc(div));
    
    free_nodes(fib);

    return 0;
}