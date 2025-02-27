#include <stdio.h>
#define v 4
#define e 4
int stack[v];
int top=-1;

void push(int n){
    top=top+1;
    stack[top]=n;
}

int pop(){
    int pv=stack[top];
    top--;
    return pv;
}

void createmat(int mat[][v], int edges[][2]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        mat[x][y] = 1;
        mat[y][x] = 1; 
    }
}


void dfs(int adjmat[][v], int visited[],int s){
    push(s);
    while(top!=-1){
        int p=pop();
        if(visited[p]==0){
            printf("%d\t",p);
            visited[p]=1;
        }
        for(int i=v-1;i>=0;i--){
            if(adjmat[p][i]==1&&visited[i]==0){
                push(i);
            }
        }
    }
}

void printMatrix(int mat[][v]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int edges[e][2] = {{0, 1}, {0, 2}, {2, 3}, {1, 3}};
    int adjmat[v][v];
    createmat(adjmat, edges);
    printMatrix(adjmat);
    int visited[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
    dfs(adjmat, visited, 0);

    return 0;
}
