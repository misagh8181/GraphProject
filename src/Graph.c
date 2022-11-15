#include <stdio.h>
#include <stdlib.h>

int secondTime=0;

void recursiveForGeraph(int temp,int numberOfV,int tempColor,int n,int m,int color[n],int u[m],int v[m]){
    // search about v[numberOfU] have connection or not
    for(int i=0;i<m;i++){
        if(temp==u[i] && numberOfV!=i){
            int edame=1;
            int tempColor1=tempColor;
            if(color[v[i]-1]==-1){
                color[v[i]-1]=tempColor1; 
            }else if (color[v[i]-1]!=-1){
                if(color[v[i]-1]!=tempColor1){
                    printf("No");
                    exit(0);
                }
                if(color[v[i]-1]==tempColor1){
                    edame=0;
                }
            }
            if(edame==1){
                if(tempColor1==1){
                    tempColor1=2;
                }else{
                    tempColor1=1;
                }
                int stop=1;
                for(int j=0;color[j];j++){
                    if(color[j]==-1){
                        stop=0;
                    }
                }
                if(stop==1){
                    if(secondTime==1){
                        printf("YES");
                        exit(0);
                    }
                    secondTime=1;
                }
                recursiveForGeraph(v[i],i,tempColor1,n,m,color,u,v);
            }
        }
        //search about u[numberOfU] have connection or not
        if(temp==v[i] && numberOfV!=i){
            int edame=1;
            int tempColor2=tempColor;
            if(color[u[i]-1]==-1){
                color[u[i]-1]=tempColor2; 
            }else if (color[u[i]-1]!=-1){
                if(color[u[i]-1]!=tempColor2){
                    printf("NO");
                    exit(0);
                } if(color[v[i]-1]==tempColor2){
                    edame=0;
                }
            }   
            if(edame==1){
                if(tempColor2==1){
                    tempColor2=2;
                }else{
                    tempColor2=1;
                }
                int stop=1;
                for(int j=0;color[j];j++){
                    if(color[j]==-1){
                        stop=0;
                    }
                }
                if(stop==1){
                    if(secondTime==1){
                        printf("YES");
                        exit(0);
                    }
                    secondTime=1;
                }
                recursiveForGeraph(u[i],i,tempColor2,n,m,color,u,v);
            }
        }
    }
}
 
int main(){
    // Autherod by Misagh Maleki & Fatmeh Ebrahimi

    /* n=vertex , m=mane
     defualt -> u[0]
     vertex -> (1 -> n)
     color -> 1/2*/

    //Input part
    int n, m;
    int vertex[n];
    int color[n];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        vertex[i] = i + 1;
    }
    int u[m];
    int v[m];
    for (int i = 0; i < m; i++){
        scanf("%d %d", &u[i], &v[i]);
    }
    for(int i=0;i<n;i++){
        color[i]=-1;
    }
    //end of Input part

    // For single vertexes
    for(int i=0;i<n;i++){
        int checkForSingle=0;
        for(int j=0;j<m;j++){
            if(vertex[i]==u[j]){
                checkForSingle=1;
            }
        }
        for(int j=0;j<m;j++){
            if(vertex[i]==v[j]){
                checkForSingle=1;
            }
        }
        if(checkForSingle==0){
            color[i]=1;
        }
    }
    
    color[u[0]-1]=1;
    for(int i=0;i<m;i++){
        if(u[0]==u[i]){
            color[v[i]-1]=2;
            recursiveForGeraph(v[i],i,1,n,m,color,u,v);
        }
        if(u[0]==v[i]){
            color[u[i]-1]=2;
            recursiveForGeraph(u[i],i,1,n,m,color,u,v);
        }
    }
    printf("YES");
      
}