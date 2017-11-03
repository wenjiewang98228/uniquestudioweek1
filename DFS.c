#include <stdio.h>

typedef struct vertex{
    int isVisited;
    int eachTime;
    int preVertex;
}vertex;

int V;
int E;
int map[11][11];
vertex vt[11];
int allTime;

void  depthFirstSearch();
void DFSvisit(int v);

int main(){

    printf("set V(<=10):");
    scanf("%d",&V);
    printf("set E(<=10&&<=V*(V-1)/2:");
    scanf("%d",&E);

    int outVertex,inVertex;

    printf("set connected points:\n");
    for(int i = 0; i < E; i++){
        scanf("%d %d",&outVertex,&inVertex);

        if(outVertex > V || inVertex > V){
            printf("out of range");
        }
        else{
            map[outVertex][inVertex] = 1;
        }
    }

    depthFirstSearch();

    for (int i = 1; i <= V; i++)
    {
    printf("Number:%d  PRE:%d  eachTime:%d\n", i, vt[i].preVertex, vt[i].eachTime);
    }

    return 0;
}

void depthFirstSearch(){
    allTime = 0;

    for(int i = 1;i <= V; i++){
        vt[i].isVisited = 0;
        vt[i].preVertex = -1;
    }

    for(int v = 1; v <= V; v++){
        if(!vt[v].isVisited){
            DFSvisit(v);
        }
    }

}

void DFSvisit(int v){
    allTime++;

    vt[v].eachTime = allTime;
    vt[v].isVisited = 1;

    for(int u = 1; u <= V; u++){
        if(map[v][u] == 1 && !vt[u].isVisited ){
            vt[u].preVertex = v;
            DFSvisit(u);
        }
    }

    allTime++;
}
