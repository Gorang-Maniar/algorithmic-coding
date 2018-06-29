********graphs and stuff*****************
#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
struct adjListNode{
	int dest;
	struct adjListNode *next;
};
struct adjList{
	struct adjListNode *head;
};
struct Graph{
	int v;
	struct adjList *array;
};
struct adjListNode * newadjListNode(int desti)
{
	struct adjListNode *newnode = new adjListNode();
	newnode->dest=desti;
	newnode->next=NULL;
	return newnode;
}
struct Graph * createGraph(int v)
{
	struct Graph *newGraph=new Graph();
	newGraph->v=v;
	newGraph->array=new adjList[v]();
	return newGraph;
	int i=0;
	for(i=0;i<v;i++)
	{
		newGraph->array[i].head=NULL;
	}
	return newGraph;
}
void addEdge(struct Graph * graph,int src,int dest)
{
	struct adjListNode * newnode=newadjListNode(dest);
	newnode->next=graph->array[src].head;
	graph->array[src].head=newnode;
}
void printGraph(struct Graph *graph)
{
	for(int i=0;i<graph->v;i++)
	{
		struct adjListNode *ptr=graph->array[i].head;
		while(ptr!=NULL)
		{
			cout<<ptr->dest<<"->";
			ptr=ptr->next;
		}
		cout<<endl;
	}
}
struct QueueNode{
	int val;
	QueueNode *next;
};
struct Queue{
	QueueNode *first;
	QueueNode *last;
	
};
struct Queue * newQueue()
{
	struct Queue * newnode=new Queue();
	newnode->first=NULL;
	newnode->last=NULL;
}
void enque(Queue *q,int x)
{
	struct QueueNode * newnode=new QueueNode();
	newnode->val=x;
	newnode->next=q->first;
	if(q->last==NULL)
	q->last=newnode;
	q->first=newnode;
}
int deque(Queue *q)
{
	int val;
	QueueNode *itr=q->first;
	if(itr==NULL)
	return -1;
	if(itr->next==NULL)
	{
		val=itr->val;
		q->first=NULL;
		q->last=NULL;
	}
	else
	{
		while((itr->next)->next!=NULL)
		itr=itr->next;
		val=itr->next->val;
		itr->next=NULL;
	}
	return val;
}
int isempty(Queue *q)
{
	if(q->first==NULL)
	return 1;
	else
	return 0;
}
struct StackNode{
	int val;
	StackNode *next;
};
struct Stack{
	StackNode *top;
};
struct Stack * newStack()
{
	struct Stack *newnode=new Stack();
	newnode->top=NULL;
	return newnode;
}
void push(Stack *stack,int val)
{
	StackNode *newnode=new StackNode();
	newnode->val=val;
	newnode->next=stack->top;
	stack->top=newnode;
}
int pop(Stack *stack )
{
	if(stack->top==NULL)
	return -1;
	int val=stack->top->val;
	stack->top=stack->top->next;
	return val;
}
int isemptyStack(Stack *stack)
{
	if(stack->top==NULL)
	return 1;
	return 0;
}
void BFS(Graph *graph,int s)
{
	bool *visited=new bool[graph->v];
	for(int i=0;i<graph->v;i++)
	{
		visited[i]=false;
	}
	Queue *q=newQueue();
	visited[s]=true;
	enque(q,s);
	while(!isempty(q))
	{
		int val=deque(q);
		cout<<"visiting "<<val<<endl;
		adjListNode *itr=graph->array[val].head;
		while(itr!=NULL)
		{
			if(!visited[itr->dest])
			{
				enque(q,itr->dest);
				visited[itr->dest]=1;
			}
			itr=itr->next;
		}
}
}
void DFS(Graph *graph,int s)
{
	bool *visited=new bool[graph->v];
	for(int i=0;i<graph->v;i++)
	{
		visited[i]=false;
	}
	Stack *st=newStack();
	visited[s]=true;
	push(st,s);
	while(!isemptyStack(st))
	{
		int val=pop(st);
		cout<<"visiting "<<val<<endl;
		adjListNode *itr=graph->array[val].head;
		while(itr!=NULL)
		{
			if(!visited[itr->dest])
			{
				visited[itr->dest]=true;
				push(st,itr->dest);
			}
			itr=itr->next;
		}
	}
}
int main()
{
	int V=5;
	struct Graph *graph=createGraph(V);
	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    cout<<"BFS is"<<endl;
    BFS(graph,0);
    cout<<"DFS is"<<endl;
    DFS(graph,0);
}



******************************************************************************************************************************



***********airplane game**************************

#include <iostream> 
using namespace std; 
int a[13][5], b[5][5]; 
 
void detonate(int row){
	for (int i = row; i > row - 5; i--){
		for (int j = 0; j < 5; j++){ 
			b[row - i][j] = 0;
			if (i >= 0 && a[i][j] == 2)      
			{              
				b[row - i][j] = 2;          
				a[i][j] = 0;    
			}
		}
	}
}
void unDetonate(int row){     
	for (int i = row; i > row - 5; i--){     
		for (int j = 0; j < 5; j++)         {  
			if (i >= 0 && b[row - i][j] == 2)     
			{
				a[i][j] = 2;           
			} 
		}
	}
} 
 
void getMaxCoins(int pos, int coins, int n, int &maxCoins){    
	if (pos < 0 || pos > 4 || coins < 0) return;    
	if (a[n - 1][pos] == 2) coins -= 1;    
	else if (a[n - 1][pos] == 1) coins += 1; 
 
    if (n == 1){    
	    if (coins > maxCoins) 
		    maxCoins = coins;    
	    return;   
    }
	else{   
		// 3 options     
		// move right     
		getMaxCoins(pos + 1, coins, n - 1, maxCoins);     
		// move left        
		getMaxCoins(pos - 1, coins, n - 1, maxCoins);   
		// not move         
		getMaxCoins(pos, coins, n - 1, maxCoins);     
	}
} 
 
int main(){     
	int t, n, i, j, k, coins, maxCoins;   
	cin >> t;   
	for (i = 0; i < t; i++){      
		cin >> n;      
		maxCoins = -1;  
		for (j = 0; j < n; j++){     
			for (k = 0; k < 5; k++){     
				cin >> a[j][k];          
			}
		}
		for (j = 0; j < 5; j++) 
			a[n][j] = 0;     
		a[n][2] = 3;       
		for (j = n - 1; j > 0 ; j--)       
		{
			coins = -1;      
			//detonate         
			detonate(j);        
			getMaxCoins(2, 0, n, coins);      
			if (coins > maxCoins) 
				maxCoins = coins;     
			unDetonate(j);       
			// undetonate 
 
        	}      
		cout << ((maxCoins < 0) ? -1 : maxCoins) << endl; 
	}
} 



************************************************************************************************************************



***basestations***
#include<iostream>
using namespace std;
int a[50][50],visited[50][50],n,m;
int issafe(int i,int j)
{
	if(i<0||j<0||i>=n||j>=m)
	return 0;
	if(visited[i][j])
	return 0;
	return 1;
}
int dfsval(int i,int j,int l,int cost)
{
	l++;
	cost=cost+a[i][j];
	visited[i][j]=1;
	if(l==4)
	{
		visited[i][j]=0;
		return cost;
	}
	int ans=INT_MIN;
	if(issafe(i+1,j))
	ans=max(ans,dfsval(i+1,j,l,cost));
	if(issafe(i-1,j))
	ans=max(ans,dfsval(i-1,j,l,cost));
	if(issafe(i,j-1))
	ans=max(ans,dfsval(i,j-1,l,cost));
	if(issafe(i,j+1))
	ans=max(ans,dfsval(i,j+1,l,cost));
	if(j%2==0)
	{
		if(issafe(i-1,j-1))
		ans=max(ans,dfsval(i-1,j-1,l,cost));
		if(issafe(i-1,j+1))
		ans=max(ans,dfsval(i-1,j+1,l,cost));
	}
	else
	{
		if(issafe(i+1,j-1))
		ans=max(ans,dfsval(i+1,j-1,l,cost));
		if(issafe(i+1,j+1))
		ans=max(ans,dfsval(i+1,j+1,l,cost));
	}
	visited[i][j]=0;
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>a[i][j];
	int ans=INT_MIN;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		for(int k=0;k<n;k++)
		for(int l=0;l<m;l++)
		visited[k][l]=0;
		int x=dfsval(i,j,0,0);
		//cout<<x<<endl;
		ans=max(ans,x);
		if(j%2==0)
		{
			if(issafe(i,j-1)&&issafe(i,j+1)&&issafe(i-1,j))
			ans=max(ans,(a[i][j]+a[i][j-1]+a[i][j+1]+a[i-1][j]));
			if(issafe(i-1,j-1)&&issafe(i-1,j+1)&&issafe(i+1,j))
			ans=max(ans,(a[i][j]+a[i-1][j-1]+a[i-1][j+1]+a[i+1][j]));
		}
		else
		{
			if(issafe(i-1,j)&&issafe(i+1,j-1)&&issafe(i+1,j+1))
			ans=max(ans,(a[i][j]+a[i-1][j]+a[i+1][j-1]+a[i+1][j+1]));
			if(issafe(i+1,j)&&issafe(i,j-1)&&issafe(i,j+1))
			ans=max(ans,(a[i][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]));
		}
	}
	cout<<ans*ans<<endl;
	}
}





**********************************************************************************************************************************



******candies*****************
#include<iostream>
using namespace std;
int dp[101][101];
int calcdp(int c,int g)
{
	if(c==0)
	return -1;
	if(dp[c][g]!=-1)
	return dp[c][g];
	int maxm=0;
	for(int i=1;i<=c;i++)
	{
		maxm=max(maxm,calcdp(c-i,g-1)*i);
	}
	dp[c][g]=maxm;
	return maxm;
}
int main()
{
	int t,c,g;
	cin>>t;
	while(t--)
	{
		cin>>c>>g;
		for(int i=0;i<=c;i++)
		{
		     for(int j=0;j<=g;j++)
			 dp[i][j]=-1;	
		}
		for(int i=1;i<=c;i++)
	    dp[i][1]=i;
	int ans=calcdp(c,g);
	cout<<ans<<endl;
	}
}





********************************************************************************************************************************


***************common ancester****************************
#include<iostream>
using namespace std;
int parent[10005],tree[10005][2];
struct StackNode{
	int val;
	struct StackNode *next;
};
struct Stack{
	struct StackNode *top;
};
void push(struct Stack *s,int val)
{
	struct StackNode *newnode=new StackNode();
	newnode->val=val;
	newnode->next=NULL;
	newnode->next=s->top;
	s->top=newnode;
}
int pop(struct Stack *s)
{
	if(s->top==NULL)
	return -1;
	int val=s->top->val;
	s->top=s->top->next;
	return val;
}
int empty(struct Stack *s)
{
	if(s->top!=NULL)
	return 0;
	return 1;
}
struct Stack * findpath(int s)
{
	//cout<<"inside findpath "<<s<<endl;
	struct Stack *st=new Stack();
	st->top=NULL;
	int x=s;
	while(x!=1)
	{
		//cout<<"pushing "<<x<<endl;
		push(st,x);
		x=parent[x];
	}
	//cout<<"pushing "<<1<<endl;
	push(st,1);
	//cout<<"exiting findpath "<<s<<endl;
	return st;
}
int findsize(int node)
{
	if(tree[node][0]==-1&&tree[node][1]==-1)
	return 1;
	else
	{
		int a1=0;
		int a2=0;
		if(tree[node][0]!=-1)
		a1=findsize(tree[node][0]);
		if(tree[node][1]!=-1)
		a2=findsize(tree[node][1]);
		return 1+a1+a2;
	}
}
int main()
{
	int t,v,e,s1,s2,x,y;
	cin>>t;
	while(t--)
	{
		cin>>v>>e>>s1>>s2;
		for(int i=0;i<=v;i++)
		{
			parent[i]=0;
			tree[i][0]=-1;
			tree[i][1]=-1;
		}
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			parent[y]=x;
			if(tree[x][0]==-1)
			tree[x][0]=y;
			else
			tree[x][1]=y;	
		}
		//for(int i=1;i<=v;i++)
		//cout<<parent[i]<<" ";
		//cout<<endl;
		struct Stack *s=findpath(s1);
		struct Stack *m=findpath(s2);
		struct StackNode *itr1,*itr2;
		itr1=s->top;
		itr2=m->top;
		if(itr1->next!=NULL&&itr2->next!=NULL)
		while(itr1->next->val==itr2->next->val)
		{
			itr1=itr1->next;
			itr2=itr2->next;
		}
		int size=findsize(itr1->val);
		cout<<itr1->val<<" "<<size<<endl;
		
		
	}
}



*******************************************************************************************************************************



********sell_products**********

#include<iostream>
using namespace std;
int m[8][4];
int dp[101][101][101]={-1};

int func(int cpu,int memory,int board,int cpu_price,int memory_price,int models)
{
  int temp2=0;
  if(dp[cpu][memory][board]!=-1)
  return dp[cpu][memory][board];
  else
  {
    int temp1=cpu*cpu_price+memory*memory_price;
    for(int i=0;i<models;i++)
    {
      if(cpu-m[i][0]>=0 && memory-m[i][1]>=0 && board-m[i][2]>=0)
      {temp2=max(temp2,func(cpu-m[i][0],memory-m[i][1],board-m[i][2],cpu_price,memory_price,models)+m[i][3]);
      }
      
    }
  dp[cpu][memory][board]=max(temp1,temp2);
  return dp[cpu][memory][board];
  }
}
int main()
{
  int t;
  cin>>t;
  int cpu,memory,board,cpu_price,memory_price,models;
 
  while(t--)
  {
      cin>>cpu>>memory>>board>>cpu_price>>memory_price>>models;
      for(int i=0;i<models;i++)
      {
        cin>>m[i][0]>>m[i][1]>>m[i][2]>>m[i][3];
      }
      for(int i=0;i<=cpu;i++)
      {
        for(int j=0;j<=memory;j++)
        {
          for(int k=0;k<=board;k++)
          dp[i][j][k]=-1;
        }
      }
      cout<<func(cpu,memory,board,cpu_price,memory_price,models)<<endl;
    
  }
  return 0;
  
}



*************************************************************************************************************************



*****************fishery**********************
#include<iostream>
using namespace std;
int n,g[3],c[3],s[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int issafe(int i)
{
	if(i<0||i>=n)
	return 0;
	else
	return 1;
}
int getres(int i,int j,int occu[])
{
	//cout<<"getres("<<i<<","<<j<<")"<<endl;
	if(j==3)
	return 0;
	int x=s[i][j];
	int pos=0;
	int ans=0;
	for(int k=0;k<c[x]-1;)
	{
		if(issafe(g[x]-1+pos))
		{
			if(!occu[g[x]-1+pos])
			{
				occu[g[x]-1+pos]=1;
				k++;
				ans+=pos+1;
				continue;
			}
		}
		if(issafe(g[x]-1-pos))
		{
			if(!occu[g[x]-1-pos])
			{
				occu[g[x]-1-pos]=1;
				k++;
				ans+=pos+1;
			}
		}
		pos++;
	}
	int safe=0;
	if(issafe(g[x]-1+pos))
	if(!occu[g[x]-1+pos])
	safe=1;
	if(issafe(g[x]-1-pos))
	if(!occu[g[x]-1-pos])
	safe=1;
	while(!safe)
	{
		pos++;
		if(issafe(g[x]-1+pos))
	if(!occu[g[x]-1+pos])
	safe=1;
	if(issafe(g[x]-1-pos))
	if(!occu[g[x]-1-pos])
	safe=1;		
	}
	int res1=100000, res2=100000,occu1[100];
	if(issafe(g[x]-1+pos))
	if(!occu[g[x]-1+pos])
	{
		for(int d=0;d<n;d++)
		occu1[d]=occu[d];
		occu1[g[x]-1+pos]=1;
		res1=getres(i,j+1,occu1);
	}
	if(issafe(g[x]-1-pos))
	if(!occu[g[x]-1-pos])
	{
		for(int d=0;d<n;d++)
		occu1[d]=occu[d];
		occu1[g[x]-1-pos]=1;
		res2=getres(i,j+1,occu1);
	}
	//cout<<"returning "<<ans+pos+1+min(res1,res2)<<endl;
	return ans+pos+1+min(res1,res2);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<3;i++)
		cin>>g[i]>>c[i];
		int res=100000,occu[100];
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<n;j++)
			occu[j]=0;
			res=min(res,getres(i,0,occu));
		}
		cout<<res<<endl;		
	}
}


**************************************************************************************************

*****flipgame********
#include<iostream>
using namespace std;
int n,a[5][5];
int issafe(int i,int j)
{
	if(i<0||j<0||i>=n||j>=n)
	return 0;
	else
	return 1;
}
void flip(int i,int j,int &wc)
{
	int tempwc=0,tempbc=0;
	if(issafe(i+1,j))
	{
		if(a[i+1][j]==0)
		tempwc++;
		else
		tempbc++;
		a[i+1][j]=1-a[i+1][j];
		
	}
	if(issafe(i-1,j))
	{
		if(a[i-1][j]==0)
		tempwc++;
		else
		tempbc++;
		a[i-1][j]=1-a[i-1][j];
	}
	if(issafe(i,j+1))
	{
		if(a[i][j+1]==0)
		tempwc++;
		else
		tempbc++;
		a[i][j+1]=1-a[i][j+1];
	}
	if(issafe(i,j-1))
	{
		if(a[i][j-1]==0)
		tempwc++;
		else
		tempbc++;
		a[i][j-1]=1-a[i][j-1];
	}
	if(a[i][j]==0)
	tempwc++;
	else
	tempbc++;
	a[i][j]=1-a[i][j];
	wc=wc+tempbc-tempwc;
}
int minflips(int i,int j,int wc,int flips)
{
	if(wc==n*n)
	return flips;
	if(i==n)
	return INT_MAX;
	flip(i,j,wc);
	int newi=i+(j+1)/n;
	int newj=(j+1)%n;
	int x=minflips(newi,newj,wc,flips+1);
	flip(i,j,wc);
	int y=minflips(newi,newj,wc,flips);
	return min(x,y);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int whitecount=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			whitecount++;
		}
		int x=minflips(0,0,whitecount,0);
		cout<<x<<endl;	
	}
}




*****************************************************************************************************************************

******hanaro*********

#include<iostream>
using namespace std;
long long n,x[1000001],y[1000001],selected[1000001],val[1000001];
long long int rounde (double x)
{
	long long int ans=x+0.5;
	return ans;
}
long long int dist(long long int i,long long int j)
{
	long long int d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	return d;
}
double prim(long long int l,double e)
{
	if(l==n)
	return 0.0;
	l++;
	long long int min=INT_MAX,mini=-1;
	for(long long int i=0;i<n;i++)
	{
		if(val[i]<min&&!selected[i])
		{
			min=val[i];
			mini=i;
		}
	}
	selected[mini]=1;
	for(long long int i=0;i<n;i++)
	{
		if(dist(mini,i)<val[i])
		val[i]=dist(mini,i);
	}
	return e*double(min)+prim(l,e);	
}
int main()
{
	int t;
	double e;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(long long int i=0;i<n;i++)
		cin>>x[i];
		for(long long int j=0;j<n;j++)
		cin>>y[j];
		cin>>e;
		for(long long int i=0;i<n;i++)
		selected[i]=0;
		for(long long int i=0;i<n;i++)
		val[i]=dist(0,i);
		double xx=prim(0,e);
		cout<<"The cost is "<<rounde(xx)<<endl;
	}
}



********************************************************************************************************************************


***********number of valid permutations****************
#include<iostream>
using namespace std;
int n,digit[10];
int numvalidperm(int set,int countset)
{
	//cout<<"numvalidperm ("<<set<<","<<countset<<")"<<endl;
	if(countset>3)
	return 0;
	if(countset==1)
	{
		return 1;
	}
	if(countset==2)
	{
		if(digit[0]==set)
		{
			return 0;
		}
		return 2;
	}
	if(countset==3)
	{
		if(digit[0]==set)
		{
			int res=0;
			if(digit[1]==set)
			res++;
			if(digit[2]==set)
			res++;
		}
		else
		{
			int res=0;
			if(digit[1]==set)
			{
				res+=2;
			}
			else if(digit[2]==set)
			{
				int j=0,num[2];
				for(int i=1;i<10;i++)
				{
					if(digit[i]==set&&i!=2)
					{
						num[j]=i;
						j++;
					}
				}
				int num1=num[0]*10+num[1];
				int num2=num[1]*10+num[0];
				if(num1<=55)
				res++;
				if(num2<=55)
				res++;
			}
			return res;
		}
	}
}
int findans()
{
	int count1=0,count2=0;
	for(int i=0;i<=9;i++)
	{
		if(digit[i]==1)
		count1++;
		else if(digit[i]==2)
		count2++;
	}
	if(count1==0||count2==0)
	return 0;
	return numvalidperm(1,count1)*numvalidperm(2,count2);
}
int find(int i)
{
	//cout<<"find("<<i<<")"<<endl;
	if(i>9)
	{
		return findans();
	}
	if(digit[i]==0)
	return find(i+1);
	else
	{
		int ans=0;
		digit[i]=2;
		ans+=find(i+1);
		digit[i]=1;
		ans+=find(i+1);
		return ans;
	}
}
int main()
{
	int t,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<10;i++)
		digit[i]=0;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			digit[x]=1;
		}
		int ans=find(0);
		cout<<ans<<endl;
		
	}
}


******************************************************************************************************************

**************marathon****************
#include<iostream>
#include<stdio.h>

long int tim[5], ener[5];
int dp[1000][1000];
using namespace std;

//
//long int finds(int h, int d)
//{
//	//if(h < 0) return 1000000;
//	//if(h == 0 && d != 0) return 100000;
//	if(d == 0) return 0;
//	
//	long int mini = 100000000;
//	/*if(d < 0)
//		return mini;*/
//	for(int i = 0; i < 5; i++)
//	{
//		int j = 1;
//		while(1)
//		{
//			if(h < 0 || h - ener[i] < 0)
//			{
//				continue;
//			}
//			if(h - ener[i] >= 0 && !(h - ener[i] == 0 && (d - 1) != 0))
//			{
//				long int df = finds(h - ener[i], d - 1);
//
//				if(tim[i] + df < mini)
//				{
//					mini = tim[i] + df;
//				}
//			}
//			//cout << mini << endl;
//		}
//	}
//	
//	//return mini;
//}

int min(int x, int y)
{
	return (x < y)?x:y;
}
int main()
{

	//int n;
	long int d,h,a,b;
	cin >> h >> d;

	for(int i = 0; i < 5; i++)
	{
		cin >> a>>b >> ener[i];
		tim[i] = a * 60 + b;

		//cout << tim[i] << " " << ener[i] << endl;
	}
	for(int i = 0; i <= d; i++)
	{
		for(int j = 0; j <= h; j++)
		{
			dp[i][j] = 0;
		}
	}
	for(int k = 0; k < 5;k++)
	for(int i = ener[k]; i <=h ; i++)
	{
		dp[0][i] = 0;
		if(!dp[1][i]) dp[1][i] = tim[k];
	}
	//int mini = 999999;
	for(int i = 0; i <= d; i++)
	{
		for(int j = 0; j <= h; j++)
		{
			if(dp[i][j] == 0) dp[i][j]=999999;
		}
	}
	
	for(int i = 2; i <= d; i++)
	{
		for(int j = 0; j <=h; j++)
		{
			long int mini = 9999999;
			for(int k = 0; k < 5; k++)
			{
				if(j > ener[k])
				mini=min(mini,tim[k]+ dp[i-1][j-ener[k]]);
			}
			dp[i][j] = mini;
		}
	}
	cout << dp[d][h] / 60 << " " << dp[d][h] % 60 << endl;

	/*long int g=finds(h, d);
	cout << "hhh\n";
	cout << g << endl;
	*/
	system("pause");
	
}



*******************************************************************************************************************

**************marbles****************
#include<iostream>
using namespace std;
int changedir[5][6]={{0,0,0,0,0,0},{1,2,4,3,2,2},{2,4,1,1,3,1},{3,1,2,4,4,4},{4,3,3,2,1,3}};
int n,a[25][25],b[25][25],h[25][25],visited[25][25][5];
void init()
{
	for(int k=0;k<n;k++)
	for(int l=0;l<n;l++)
	{
		b[k][l]=a[k][l]/10;
		h[k][l]=a[k][l]%10;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int k=0;k<5;k++)
	visited[i][j][k]=-1;
	
}
void findnewpos(int dir,int &i,int &j)
{
	if(dir==1)
	{
		i=(i-1+n)%n;
	}
	if(dir==2)
	{
		i=(i+1)%n;
	}
	if(dir==3)
	{
		j=(j-1+n)%n;
	}
	if(dir==4)
	{
		j=(j+1)%n;
	}
	return;
}
int findmax(int i,int j,int dir,int count,int changecount)
{
	//cout<<"findmax("<<i<<","<<j<<","<<dir<<","<<count<<")"<<endl;
	if(visited[i][j][dir]==changecount)
	return count;
	visited[i][j][dir]=changecount;
	if(b[i][j]!=0&&h[i][j]!=0)
	{
		dir=changedir[dir][b[i][j]];
		changecount++;
		h[i][j]--;
		if(h[i][j]==0)
		{
			count++;
			b[i][j]=0;
		}
	}
	findnewpos(dir,i,j);
	return findmax(i,j,dir,count,changecount);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		int ans=INT_MIN;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				init();
				ans=max(ans,findmax(i,j,1,0,0));
				init();
				ans=max(ans,findmax(i,j,2,0,0));
				init();
				ans=max(ans,findmax(i,j,3,0,0));
				init();
				ans=max(ans,findmax(i,j,4,0,0));
			}
		}
		cout<<ans<<endl;	
	}
}


**********************************************************************************************************************************



********************metal stick******************************
#include<iostream>
using namespace std;
int external[100];
int internall[100];
int issafe(int visited[],int i,int j)
{
	if(visited[j])
	return 0;
	if(external[j]==internall[i])
	return 1;
	else
	return 0;
}
void dfs(int i,int n,int visited[],int pos,int &ans,int ansi[],int ansj[],int visiti[],int visitj[])
{
	pos++;
	visited[i]=1;
	visiti[pos-1]=external[i];
	visitj[pos-1]=internall[i];
	int flag=0;
	for(int j=0;j<n;j++)
	{
		if(issafe(visited,i,j))
		{
			flag=1;
			dfs(j,n,visited,pos,ans,ansi,ansj,visiti,visitj);
		}
	}
	if(flag==0)
	{
		if(pos>ans)
		{
			ans=pos;
			for(int j=0;j<pos;j++)
			{
				ansi[j]=visiti[j];
				ansj[j]=visitj[j];
			}
		}
	}
	visited[i]=0;
	visiti[pos-1]=-1;
	visitj[pos-1]=-1;
}
int main()
{
	int x,n,visited[100],ansi[100],ansj[100];
	cin>>x;
	while(x--){
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>external[i]>>internall[i];
		for(int i=0;i<n;i++)
		visited[i]=0;
		int ans=0,visiti[100],visitj[100];
		for(int i=0;i<n;i++)
		{
		    dfs(i,n,visited,0,ans,ansi,ansj,visiti,visitj);
		}
		cout<<ans<<endl;
		for(int i=0;i<ans;i++)
		{
			cout<<ansi[i]<<" "<<ansj[i]<<" ";
		}
		cout<<endl;
	}
}



********************************************************************************************************************************


***********mountain climbing***********************
#include<iostream>
using namespace std;
int m,n,visited[100][100],a[100][100];
int issafe(int i,int j)
{
	if(i<0||i>=m||j<0||j>=n)
	return 0;
	else if(visited[i][j])
	return 0;
	else if(a[i][j]==1||a[i][j]==3)
	return 1;
	return 0;
}
int dfs(int i,int j)
{
	if(a[i][j]==3)
	return 0;
	visited[i][j]=1;
	int tempans=100000;
	if(issafe(i,j+1))
    tempans=min(tempans,dfs(i,j+1));
    if(issafe(i,j-1))
    tempans=min(tempans,dfs(i,j-1));
    int x=i;
    do{
    	x--;
    	if(x<0)
    	break;
	}while(a[x][j]!=1&&a[x][j]!=3);
	if(issafe(x,j))
	tempans=min(tempans,max(i-x,dfs(x,j)));
	x=i;
	do{
		x++;
		if(x>=m)
		break;
	}while(a[x][j]!=1&&a[x][j]!=3);
	if(issafe(x,j))
	tempans=min(tempans,dfs(x,j));
	visited[i][j]=0;
	return tempans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		visited[i][j]=0;
		int ans=dfs(m-1,0);
		cout<<ans<<endl;
	}
}



****************************************************************************************************************************


**************optimal path**************
#include<iostream>
using namespace std;
int ox,oy,hx,hy,x[100],y[100];
int abs(int x)
{
	if(x<0)
	return -x;
	else
	return x;
}
int findcost(int x1,int y1,int x2,int y2)
{
	int cost=abs(x1-x2)+abs(y1-y2);
	return cost;
}
int issafe(int visited[],int j)
{
	if(visited[j])
	return 0;
	else
	return 1;
}
void dfs(int visited[],int i,int p,int &ans,int n,int cost)
{
	p++;
	visited[i]=1;
	if(p==n)
	{
		cost=cost+findcost(x[i],y[i],hx,hy);
		if(cost<ans)
		ans=cost;
		visited[i]=0;
		return;
	}
	for(int j=0;j<n;j++)
	{
		if(issafe(visited,j))
		{
			dfs(visited,j,p,ans,n,cost+findcost(x[i],y[i],x[j],y[j]));
		}
	}
	visited[i]=0;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>ox>>oy>>hx>>hy;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		int visited[100];
		for(int i=0;i<n;i++)
		visited[i]=0;
		int ans=100000;
		for(int i=0;i<n;i++)
		{
			dfs(visited,i,0,ans,n,findcost(ox,oy,x[i],y[i]));
		}
		cout<<ans<<endl;
	}
}



****************************************************************************************************************

***********order of task********************

#include<iostream>
using namespace std;
struct adjListNode{
	int dest;
	struct adjListNode * next;
};
struct adjList{
	struct adjListNode *head;
};
struct Graph{
	int V;
	struct adjList * array;
};
struct adjListNode * newadjListNode(int dest)
{
	struct adjListNode *newnode=new adjListNode();
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
}
struct Graph * createGraph(int v)
{
	struct Graph * g=new Graph();
	g->V=v;
	g->array=new adjList[v]();
	for(int i=0;i<v;i++)
	g->array[i].head=NULL;
	return g;
}
void addEdge(struct Graph *g,int u,int v)
{
	struct adjListNode *newnode=newadjListNode(v);
	newnode->next=g->array[u].head;
	g->array[u].head=newnode;
}
void printGraph(struct Graph *g)
{
	for(int i=0;i<g->V;i++)
	{
		struct adjListNode *itr=g->array[i].head;
		while(itr!=NULL)
		{
			cout<<"->"<<itr->dest;
			itr=itr->next;
		}
		cout<<endl;
	}
	
}
struct stackNode{
	int val;
	struct stackNode *next;
};
struct Stack{
	struct stackNode *top;
};
void push(struct Stack *s,int v)
{
	struct stackNode *newnode=new stackNode;
	newnode->val=v;
	newnode->next=NULL;
	newnode->next=s->top;
	s->top=newnode;
}
int pop(struct Stack *s )
{
	if(s->top==NULL)
	return -1;
	int val;
	val=s->top->val;
	s->top=s->top->next;
	return val;
}
int empty(struct Stack *s)
{
	if(s->top==NULL)
	return 1;
	return 0;
}
void topologicalsort(struct Graph *g, int u, bool visited[] , struct Stack *s)
{
	//cout<<"topological "<<u<<endl;
	visited[u]=1;
	struct adjListNode *itr=g->array[u].head;
	while(itr!=NULL)
	{
		int x=itr->dest;
		if(!visited[x])
		topologicalsort(g,x,visited,s);
		itr=itr->next;
	}
	push(s,u);
	//cout<<"returning "<<u<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int v,e,x,y;
		cin>>v>>e;
		struct Graph *g=createGraph(v);
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			addEdge(g,x-1,y-1);
		}
		//printGraph(g);
		bool visited[10000];
		for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}
		struct Stack *s=new Stack();
		s->top=NULL;
		for(int i=0;i<v;i++)
		if(!visited[i])
		topologicalsort(g,i,visited,s);
		while(!empty(s))
		{
			int x=pop(s);
			cout<<x+1<<" ";
		}
		cout<<endl;
	}
}



**********************************************************************************************************************************

****************pipes********************

#include<iostream>
using namespace std;
int n,l,a[100][100],visited[100][100];
void init()
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	visited[i][j]=0;
}
struct queueNode{
	int i;
	int j;
	int l;
	struct queueNode *next;
};
struct Queue{
	struct queueNode *front;
	struct queueNode *rear;
};
void push(struct Queue *q,int x,int y,int l)
{
	struct queueNode *qn=new queueNode();
	qn->i=x;
	qn->j=y;
	qn->l=l;
	qn->next=NULL;
	if(q->front==NULL)
	{
		q->front=qn;
		q->rear=qn;
		return;
	}
	q->rear->next=qn;
	q->rear=qn;
	return;
	
}
struct queueNode * pop(struct Queue * q)
{
	struct queueNode *qn=q->front;
	if(q->front->next==NULL)
	{
		q->front=NULL;
		q->rear=NULL;
	}
	q->front=q->front->next;
	return qn;
}
int empty(struct Queue *q)
{
	if(q->front==NULL)
	return 1;
	return 0;
}
int isopen(int lasti,int lastj,int i,int j,int dir)
{
	if(a[i][j]==0||a[lasti][lastj]==0)
	return 0;
	if(a[lasti][lastj]==1)
	{
		if(dir==1)
		{
			if(a[i][j]==1||a[i][j]==5||a[i][j]==2||a[i][j]==6)
			return 1;
		}
		if(dir==2)
		{
			if(a[i][j]==2||a[i][j]==4||a[i][j]==1||a[i][j]==7)
			return 1;
		}
		if(dir==3)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==5||a[i][j]==4)
			return 1;
		}
		if(dir==4)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==6||a[i][j]==7)
			return 1;
		}
	}
	if(a[lasti][lastj]==2)
	{
		if(dir==1)
		{
			if(a[i][j]==1||a[i][j]==5||a[i][j]==2||a[i][j]==6)
			return 1;
		}
		if(dir==2)
		{
			if(a[i][j]==2||a[i][j]==4||a[i][j]==1||a[i][j]==7)
			return 1;
		}
	}
	if(a[lasti][lastj]==3)
	{
		if(dir==3)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==5||a[i][j]==4)
			return 1;
		}
		if(dir==4)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==6||a[i][j]==7)
			return 1;
		}
	}
	if(a[lasti][lastj]==4)
	{
		if(dir==1)
		{
			if(a[i][j]==1||a[i][j]==5||a[i][j]==2||a[i][j]==6)
			return 1;
		}
		if(dir==4)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==6||a[i][j]==7)
			return 1;
		}
	}
	if(a[lasti][lastj]==5)
	{
		if(dir==4)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==6||a[i][j]==7)
			return 1;
		}
		if(dir==2)
		{
			if(a[i][j]==2||a[i][j]==4||a[i][j]==1||a[i][j]==7)
			return 1;
		}
	}
	if(a[lasti][lastj]==6)
	{
		if(dir==2)
		{
			if(a[i][j]==2||a[i][j]==4||a[i][j]==1||a[i][j]==7)
			return 1;
		}
		if(dir==3)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==5||a[i][j]==4)
			return 1;
		}
		
	}
	if(a[lasti][lastj]==7)
	{
		if(dir==3)
		{
			if(a[i][j]==1||a[i][j]==3||a[i][j]==5||a[i][j]==4)
			return 1;
		}
		if(dir==1)
		{
			if(a[i][j]==1||a[i][j]==5||a[i][j]==2||a[i][j]==6)
			return 1;
		}
		
	}
}
int issafe(int lasti,int lastj,int i,int j,int dir,int ln)
{
	if(i<0||j<0||i>=n||j>=n)
	return 0;
	if(ln>=l)
	return 0;
	if(isopen(lasti,lastj,i,j,dir)&&!visited[i,j])
	return 1;
	return 0;
}
int findmax(int x,int y)
{
	struct Queue *q=new Queue();
	q->front=NULL;
	q->rear=NULL;
	push(q,x,y,1);
	int count=0;
	while(!empty(q))
	{
		struct queueNode *qn=pop(q);
		int i=qn->i;
		int j=qn->j;
		int ln=qn->l;
		count++;
		if(issafe(i,j,i+1,j,2,ln+1))
		push(q,i+1,j,ln+1);
		if(issafe(i,j,i-1,j,1,ln+1))
		push(q,i-1,j,ln+1);
		if(issafe(i,j,i,j+1,4,ln+1))
		push(q,i,j+1,ln+1);
		if(issafe(i,j,i,j-1,3,ln+1))
		push(q,i,j-1,ln+1);
	}
	return count;
}
int main()
{
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>l;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		cin>>x>>y;
		init();
		findmax(x,y);
	}
}



***********************************************************************************************************************

************prize money*****************

#include<iostream>
using namespace std;
int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int x=a,y=a;
		int count=0;
		while(x!=0)
		{
			count++;
			x=x/10;
		}
		int cnt=count;
		int ch[100];
		while(y!=0)
		{
			ch[count-1]=y%10;
			y=y/10;
			count--;
		}
		int r=b;
		for(int i=0;i<cnt;i++)
		{
			int maxd=-1;
			int maxpos=-1;
			int digit=ch[i];
			for(int j=i+1;j<cnt;j++)
			{
				if(ch[j]>maxd)
				{
					maxd=ch[j];
					maxpos=j;
				}
				else if(ch[j]==maxd)
				{
					maxpos=j;
				}
			}
			if(maxd>digit)
			{
				char temp=ch[i];
				ch[i]=ch[maxpos];
				ch[maxpos]=temp;
				r--;
			}
			if(r==0)
			break;
			
		}
		if(r>0)
		{
			int pos[10];
			for(int i=0;i<10;i++)
			{
				pos[i]=-1;
			}
			int found=0;
			for(int i=0;i<cnt;i++)
			{
				int digit=ch[i];
				if(pos[digit]!=-1)
				found=1;
				else
				pos[digit]=i;
			}
			if(found==1)
			{
				r=0;
			}
			else
			{
				if(r%2==0)
				r=0;
				else
				{
				    char temp=ch[cnt-1];
				    ch[cnt-1]=ch[cnt-2];
				    ch[cnt-2]=temp;
				    r=0;
				}
			}
		}
		int sum=0;
		for(int i=0;i<cnt;i++)
		{
			sum=sum*10+ch[i];
		}
		cout<<sum<<endl;
		
}
}




*****************************************************************************************************************

***************product manufacturing********************

#include<iostream>
using namespace std;
int **a;

int getmaxprofit(int i,int count,int sum,int ni,int nj,int nk,int pi,int pj,int np,int &res){
	if(count==3 || i==np){
	//	res=max(res,sum+ni*pi+nj*pj);
		return sum+ni*pi+nj*pj;
	}
	int ret=0;
	ret=max(ret,getmaxprofit(i+1,count+1,sum,ni,nj,nk,pi,pj,np,res));
	//res=max(res,ret);
	ret=max(ret,getmaxprofit(i+1,count,sum,ni,nj,nk,pi,pj,np,res));
	//res=max(res,ret);
	for(int j=i;j<np;j++){
		int la=ni;
		int lb=nj;
		int lc=nk;
		int sm=sum;
		while((a[j][0]<=la) && (a[j][1]<=lb) && (a[j][2]<=lc)){
			la=la-a[j][0];
			lb=lb-a[j][1];
			lc=lc-a[j][2];
			sm+=a[j][3];
			ret=max(ret,getmaxprofit(i+1,count+1,sm,la,lb,lc,pi,pj,np,res));
			//res=max(res,ret);
		}
		ret=max(ret,getmaxprofit(i+1,count+1,sm,la,lb,lc,pi,pj,np,res));
		//res=max(res,ret);



	}
	return ret;

}
int main(){
	int t;
	cin>>t;
	int ni,nj,nk,np,pi,pj;
	while(t--){
	cin>>ni>>nj>>nk>>pi>>pj>>np;
	a=new int*[np];
	for (int i = 0; i < np; ++i)
	{
		a[i]=new int[4];
		/* code */
	}
	for (int i = 0; i < np; ++i)
	{
		for(int j=0;j<4;j++){
			cin>>a[i][j];
		}
		/* code */
	}
	int t;

	cout<<getmaxprofit(0,0,0,ni,nj,nk,pi,pj,np,t)<<endl;
	
}


}


*************************************************************************************************************************


****************rare elements*******************

#include<iostream>
using namespace std;
int n,path[100][100],visited[100][100],rare[100][100],rarevisited[100][100],c,overalllength;
struct queueNode{
	int i;
	int j;
	int length;
	queueNode *next;
};
struct Queue{
	queueNode *front;
	queueNode *rear;
};
struct Queue * newQueue()
{
	struct Queue * newQ=new Queue();
	newQ->front=NULL;
	newQ->rear=NULL;
	return newQ;
}
int empty(struct Queue *q)
{
	if(q->front==NULL)
	return 1;
	else
	return 0;
}
void enque(struct Queue *q,int i,int j,int l)
{
	struct queueNode *qn=new queueNode();
	qn->i=i;
	qn->j=j;
	qn->length=l;
	if(empty(q))
	{
		q->front=qn;
		q->rear=qn;
		return;
	}
	q->rear->next=qn;
	q->rear=qn;
}
void deque(struct Queue *q,int &x,int &y,int &l)
{
	if(empty(q))
	{
		x=-1;
		y=-1;
		l=-1;
		return;
	}
	struct queueNode *itr=q->front;
	if(itr->next==NULL)
	{
		x=itr->i;
		y=itr->j;
		l=itr->length;
		q->rear=NULL;
		q->front=NULL;
		return;	
	}
	x=itr->i;
	y=itr->j;
	l=itr->length;
	q->front=itr->next;
	return;
}
int issafe(int i,int j)
{
	if(i<0||j<0||i>=n||j>=n)
	return 0;
	return 1;
}
int BFSLength(int si,int sj,int rarecount)
{
	Queue * q=newQueue();
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		visited[i][j]=0;
		rarevisited[i][j]=0;
	}
	int maxlength=0;
	visited[si][sj]=1;
	enque(q,si,sj,0);
	while(!empty(q))
	{
		int x,y,l;
		deque(q,x,y,l);
		if(l>=overalllength)
		return INT_MAX;
		if(rare[x][y]==1&&!rarevisited[x][y])
		{
			rarecount++;
			rarevisited[x][y]=1;
			maxlength=max(maxlength,l);
			if(rarecount==c)
			return maxlength;	
		}
		if(issafe(x+1,y))
		{
			if(path[x+1][y]&&!visited[x+1][y])
			{
				visited[x+1][y]=1;
				enque(q,x+1,y,l+1);
			}
		}
		if(issafe(x-1,y))
		{
			if(path[x-1][y]&&!visited[x-1][y])
			{
				visited[x-1][y]=1;
				enque(q,x-1,y,l+1);
			}
		}
		if(issafe(x,y+1))
		{
			if(path[x][y+1]&&!visited[x][y+1])
			{
				visited[x][y+1]=1;
				enque(q,x,y+1,l+1);
			}
		}
		if(issafe(x,y-1))
		{
			if(path[x][y-1]&&!visited[x][y-1])
			{
				visited[x][y-1]=1;
				enque(q,x,y-1,l+1);
			}
		}
		
	}
	return INT_MAX;
}
int main()
{
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>c;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		rare[i][j]=0;
		for(int i=0;i<c;i++)
		{
			cin>>x>>y;
			rare[x-1][y-1]=1;
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>path[i][j];
		overalllength=INT_MAX;
		int mini=-1,minj=-1;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(path[i][j]==1)
			{
				int maxlength=BFSLength(i,j,0);
				if(maxlength<overalllength)
				{
					overalllength=maxlength;
					mini=i;
					minj=j;
				}
			}
		}
		cout<<overalllength<<" "<<mini<<" "<<minj<<endl;
	}
}


*************************************************************************************************************************



*****************rectangle****************

#include<iostream>
using namespace std;
int main()
{
	int t,a[100][100],b[100][100],n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		//cout<<"Taken input"<<endl;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		b[i][j]=0;
		//cout<<"updated b"<<endl;
		int cnt=-1;
		int rectrow[100],rectcol[100],rectcnt[100];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(b[i][j]==0){
				if(a[i][j]==0)
				{
					b[i][j]=1;
					//cout<<1<<endl;
				}
				else{
					int row=1,col=1;
					while(a[i+row][j]!=0&&i+row<n)
					{
						row++;
						//cout<<"1 running"<<endl;
					}
					while(a[i][col+j]!=0&&j+col<n)
					{
						col++;
						//cout<<"2 running"<<endl;
					}
					//cout<<"updating rectangle"<<endl;
					rectrow[cnt]=row;
					rectcol[cnt]=col;
					rectcnt[cnt]=row*col;
					//cout<<"rectangle size "<<row*col<<endl;
					cnt++;
					for(int x=i;x<i+row;x++)
					for(int y=j;y<j+col;y++)
					{
						b[x][y]=1;
						//cout<<"updating b1"<<endl;
					}
					//cout<<"updated b once"<<endl;
					for(int x=i;x<i+row;x++)
					{
						b[x][j+col]=1;
						//cout<<"updating b2"<<endl;
					}
					//cout<<"updated b twice"<<endl;
					for(int y=j;y<j+col;y++)
					{
						b[i+row][y]=1;
						//cout<<"updating b3"<<endl;
					}
					//cout<<"updated b thrice"<<endl;
				}
			}
			}
		}
		cout<<"count="<<(cnt+1)<<" ";
		for(int i=0;i<=cnt;i++)
		cout<<rectrow[i]<<" "<<rectcol[i]<<" ";
		cout<<endl;
		
		
	}
}


****************************************************************************************************************************


****************road replair*****************************


#include<iostream>
using namespace std;
int n,k,road[10000],dp[10000];
int minpatch(int x,int y)
{
	cout<<"minpatch("<<x<<")"<<endl;
	if(dp[x]!=-1)
	{
		cout<<"inside 1"<<endl;
		cout<<"1returning "<<dp[x]<<endl;
		return dp[x];
	}
	if(x<y+k)
	return 0;
	if(x<k+k+y&&road[x]==1)
	{
		cout<<"inside 2"<<endl;
		dp[x]=x-(y+k-1);
		cout<<"2returning "<<dp[x]<<endl;
		return dp[x];
	}
	if(road[x]==0)
	{
		cout<<"inside 3"<<endl;
		dp[x]=minpatch(x-1,y);
		cout<<"3returning "<<dp[x]<<endl;
		return dp[x];
	}
	int temp=minpatch(x-k,y)+k;
	for(int i=1;i<k;i++)
	{
		if(road[x-i]==1)
		temp=min(minpatch(x-i,y)+i,temp);	
	}
	dp[x]=temp;
	cout<<"4returning "<<temp<<endl;
	return temp;	
}
int main()
{
	int t,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<=10000;i++)
		{
			road[i]=0;
			dp[i]=-1;
		}
		int max=0;
		int min=INT_MAX;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			road[x]=1;
			if(x>max)
			max=x;
			if(x<min)
			min=x;
		}
		int ans;
		if(max<=k)
		ans=k;
		else 
		ans=minpatch(max,min);
		cout<<ans+k<<endl;
	}
}



**********************************************************************************************************************************


*****************robo fuel**********************


#include<stdio.h>
#include<string.h>
#define MAX 9
int arr[MAX];
int visited[MAX];
int tdistance=99999;
void calc_min(int n,int distance,int rem,int pindex,int cars,int ins, int g_or_d)
{
    int i;
    if(cars==n)
    {
        if(tdistance>distance)
        {
            tdistance=distance;
        }
        return;
    }
    if(rem<=0) return;
    if(ins==0 && g_or_d==0)
    {
        int k;
        for(k=1;k<=n;k++)
        {
            if(!visited[k] &&arr[k]==1)
            {
                visited[k]=1;
                //go to next gas car
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,0,0);
                //go to gas station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,1,0);
                //go to diesel station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,2,0);
                visited[k]=0;
            }
        }
    }
    if(ins==0 && g_or_d==1)
    {
        int k;
        for(k=n;k>=1;k--)
        {
            if(!visited[k] && arr[k]==2)
            {
                visited[k]=1;
                //go to next gas car
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,0,1);
                //go to gas station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,1,1);
                //go to diesel station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,2,1);
                visited[k]=0;
            }
        }
    }
    if(ins==1)
    {
        //fill gas and recall  
        calc_min(n,distance+(pindex-0),2,0,cars,0,0);
    }
    if(ins==2)
    {
        //fill diesel and recall
        calc_min(n,distance+((n+1)-pindex),2,n+1,cars,0,1);
    }

}
int main(void)
{
    int T, test_case;
    int n;
    int i;
    freopen("inp.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            scanf("%d", &arr[i]);
        }
        calc_min(n,0,2,0,0,0,0);
        if( tdistance==99999)
        {
            //May be all cars are diesel cars, go to diesel bunk and fuel it from there
            calc_min(n,n+1,2,n+1,0,0,1);
        }
        printf("Case #%d %d\n", test_case+1,tdistance);
        tdistance=99999;
    }
    getch();
}


********************************************************************************************************************************


*********************rock_mera****************************

#include<iostream>
#include<stdio.h>
using namespace std;

int a[100][100], lefti[20], righti[20],dp[100][100];
int vis[100][100];
int maxi = -9999;
int n, m;

int min(int x, int y)
{
	return (x < y)?x:y;
}

int max(int x, int y)
{
	return (x> y)?x:y;
}

int issafe(int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return 0;
	if(vis[i][j] == 1) return 0;
	if(a[i][j] == 1 || a[i][j] == 3) return 1;
	return 0;
}

int dfs(int i, int j)
{
	if(a[i][j] == 3)
	{
		dp[i][j]=0;
		return 0;
	}
	vis[i][j] = 1;
	if(dp[i][j]!=-1) return dp[i][j];
	
	int temp = 1000000;
	if(issafe(i, j+1))
	{
		temp = min(temp, dfs(i, j + 1));
	}
	if(issafe(i, j - 1))
	{
		temp = min(temp, dfs(i, j - 1));
	}
	int x = i-1;
	while(x >= 0 && (a[x][j] != 1 && a[x][j] != 3))
	{
		x--;
	}
	if(issafe(x, j))
	{
		temp = min(temp, max(i-x,dfs(x, j)));
	}

	x = i+1;
	while(x <n && (a[x][j] != 1 && a[x][j] != 3))
	{
		x++;
	}
	if(issafe(x, j))
	{
		temp = min(temp, dfs(x, j));
	}
	vis[i][j] = 0;
	dp[i][j]=temp;
	return temp;

}
int main()
{
	int t;
	int stx,sty;
	cin >> t;
	for(int e = 1; e <= t; e++)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if(a[i][j]==2)
				{
					stx=i;
					sty=j;
				}
				vis[i][j] = 0;
				dp[i][j]=-1;
			}
		}
		
		cout<<dfs(stx, sty)<<endl;
		
	}
}



*********************************************************************************************************************************


*****************sales_booth*****************

#include<iostream>
using namespace std;
int m,n,visited[100][100],a[100][100],b[100][100],count[6];
int issafe(int i,int j)
{
	if(i<0||i>=m||j<0||j>=n)
	return 0;
	if(!visited[i][j])
	return 1;
	return 0;
}
void findcluster(int i,int j)
{
	//cout<<"findcluster("<<i<<","<<j<<")"<<endl;
	visited[i][j]=1;
	if(issafe(i,j+1))
	if(a[i][j+1]==a[i][j])
	findcluster(i,j+1);
	if(issafe(i,j-1))
	if(a[i][j-1]==a[i][j])
	findcluster(i,j-1);
	if(issafe(i+1,j))
	if(a[i+1][j]==a[i][j])
	findcluster(i+1,j);
	if(issafe(i-1,j))
	if(a[i-1][j]==a[i][j])
	findcluster(i-1,j);
	count[a[i][j]]++;
}
void findzerocluster(int i,int j)
{
	//cout<<"findzerocluster("<<i<<","<<j<<")"<<endl;
	visited[i][j]=1;
	if(issafe(i,j+1))
	if(a[i][j+1]==0)
	findzerocluster(i,j+1);
	if(issafe(i,j-1))
	if(a[i][j-1]==0)
	findzerocluster(i,j-1);
	if(issafe(i+1,j))
	if(a[i+1][j]==0)
	findzerocluster(i+1,j);
	if(issafe(i-1,j))
	if(a[i-1][j]==0)
	findzerocluster(i-1,j);
	if(issafe(i,j+1))
	if(a[i][j+1]!=0)
	findcluster(i,j+1);
	if(issafe(i,j-1))
	if(a[i][j-1]!=0)
	findcluster(i,j-1);
	if(issafe(i+1,j))
	if(a[i+1][j]!=0)
	findcluster(i+1,j);
	if(issafe(i-1,j))
	if(a[i-1][j]!=0)
	findcluster(i-1,j);
	
}
void color(int i,int j,int colour)
{
	b[i][j]=colour;
	if(j+1<n)
	{
		if(b[i][j+1]==0)
		color(i,j+1,colour);
	}
	if(j-1>=0)
	{
		if(b[i][j-1]==0)
		color(i,j-1,colour);
	}
	if(i+1<m)
	{
		if(b[i+1][j]==0)
		color(i+1,j,colour);
	}
	if(i-1<n)
	{
		if(b[i-1][j]==0)
		color(i-1,j,colour);
	}
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			visited[i][j]=0;
		}
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(!visited[i][j]&&a[i][j]==0)
			{
				for(int k=1;k<=5;k++)
				count[k]=0;
				for(int k=0;k<m;k++)
				for(int l=0;l<n;l++)
				if(a[k][l]!=0)
				visited[k][l]=0;
				findzerocluster(i,j);
				int max=-1,maxcol=-1;
				for(int r=1;r<=5;r++)
				if(count[r]>=max)
				{
					maxcol=r;
					max=count[r];
				}
				color(i,j,maxcol);
				
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<b[i][j]<<" ";
			cout<<endl;
		}
	}
}





**********************************************************************************************************************************


**********************shooting balloons********************

#include<iostream>
using namespace std;
int n,a[100],dp[100][100];
int findans(int i,int j)
{
	if(dp[i][j]!=-1)
	return dp[i][j];
	int max_score=0;
	for(int k=i+1;k<j;k++)
	{
		int curr_score=0;
		curr_score=findans(i,k)+findans(k,j);
		if(i==0&&j==n+1)
		curr_score+=a[k];
		else
		{
			curr_score+=a[i]*a[j];
		}
		if(curr_score>max_score)
		max_score=curr_score;
	}
	dp[i][j]=max_score;
	return max_score;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		a[0]=1;
		a[n+1]=1;
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
		dp[i][j]=-1;
		int ans=findans(0,n+1);
		cout<<ans<<endl;
	}
}



*******************************************************************************************************************************



******************shop*****************

#include<iostream>
#include<stdio.h>

using namespace std;
int a[100][100];
int vis[100][100];
int maxi,wer,weri;
int movx[4] = {1, -1, 0, 0};
int movy[4] = {0, 0, 1, -1};
int inset[100][100];
int colour[100][100];
int count_n[6];

int colour_ze[100];
bool issafe(int x, int y, int n)
{
	if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]) return true;
	return false;
}

bool issafed(int x, int y, int n)
{
	if(x >= 0 && x < n && y >= 0 && y < n && vis[x][y]) return true;
	return false;
}

bool issafe2(int x, int y, int n)
{
	if(x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

int max(int x, int y)
{
	return (x > y)?x:y;
}


void dfs3(int u, int v, int n)
{
	colour[u][v] = 1;
	count_n[a[u][v]]++;
	for(int i = 0; i < 4; i++)
	{
		int x = u + movx[i], y = v + movy[i];
		if(issafe2(x, y, n) && !colour[x][y] && a[x][y] == a[u][v])
		{
			dfs3(x, y, n);
		}
	}
}
void dfs(int u, int v, int n)
{

	vis[u][v] = 1;
	int x, y;
	for(int i = 0; i < 4; i++)
	{
		x = u + movx[i], y = v + movy[i];
		if(issafe(x, y, n) && a[x][y] == 0)
		{
			dfs(x, y, n);
		}
	}
	for(int i = 0; i < 4; i++)
	{
		 x = u + movx[i], y = v + movy[i];
		if(issafe2(x, y, n) && a[x][y]!= 0 && !colour[x][y])
		{
			dfs3(x, y, n);
		}
	}
	
	
}

void dfsutil(int u, int v, int n,int val)
{

	//vis[u][v] = 1;
	a[u][v] = val;
	vis[u][v] = 1;
	for(int i = 0; i < 4; i++)
	{
		int x = u + movx[i], y = v + movy[i];
		if(issafe(x, y, n) && a[x][y] == 0)
		{
			dfsutil(x, y, n,val);
		}
	}
}

void dfs2(int u, int v, int n)
{

	vis[u][v] = 1;
	
	for(int i = 0; i < 4; i++)
	{
		int x = u + movx[i], y = v + movy[i];
		if(issafe(x, y, n) && a[x][y] == a[u][v])
		{
			dfs2(x, y, n);
		}
	}
}


int main()
{
	int t;
	cin >> t;
	for(int e = 1; e <= t; e++)
	{
		int n;
		cin >> n;
		//int che = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				vis[i][j] = 0; 
				inset[i][j] = 0;
				//if(a[i][j] != 0) che = 1;
			}
		}
		/*if(che == 0)
		{
			cout << "#" << e << " " << 1 << endl;
		}*/
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				//cin >> a[i][j];
				vis[i][j] = 0;
				inset[i][j] = 0;
			}
		}

		int fg = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < 6; k++) count_n[k] = 0;

				for(int s = 0; s < n; s++)
				{
					for(int z = 0; z < n; z++)
					{
						colour[s][z] = 0;
					}
				}

				if(!vis[i][j] && a[i][j]==0 )
				{
					dfs(i, j, n);
				    wer = 0;
					weri = 5;
					for(int vb = 5; vb >= 1; vb--)
					{
						if(wer < count_n[vb])
						{
							wer = count_n[vb];
							weri = vb;
						}
					}
					colour_ze[fg++] = weri;

					
				}
			}
		}

		for(int s = 0; s < n; s++)
		{
			for(int z = 0; z < n; z++)
			{
				vis[s][z] = 0;
			}
		}

		int wq = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(!vis[i][j] && a[i][j] == 0 && wq<=fg)
				{
					dfsutil(i, j, n,colour_ze[wq++]);
				}
			}
		}


		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				vis[i][j] = 0;
			}
		}
		int counti = 0;
		/*cout << endl;

		cout << endl << endl;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;

		}*/

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(!vis[i][j])
				{
					counti++;
					dfs2(i, j, n);
					//cout << counti << endl;
				}
			}

		}
		
		cout << "#" << e << " " << counti << endl;

	}
	system("pause");
}




***********************************************************************************************************************************



*************toll gates*****************


#include <stdio.h>
#include<time.h>
//  no.of.toll gate(between 5 and 20, cost at toll gate, total hire available at tollgate, minimum cost
int N,   t_cost  [22], t_hire[22], min_cost = 1000000;

void dfs(int t_pos, int bpool3, int bpool2, int bpool1, int cur_cost)
{
	int  tot_bpool  = bpool3 + bpool2 + bpool1;
	if (cur_cost > min_cost) return;   // condition important to avoid unnecessary cpu cycle
	if (t_pos == N-1)   //base condition to check last toll gate
	{
		if ( tot_bpool  < t_hire[t_pos]) cur_cost += t_cost[t_pos];
		if ( cur_cost   < min_cost) min_cost = cur_cost;
		return;
	}

   dfs(t_pos+1, bpool3 , bpool2, bpool1 , cur_cost+t_cost[t_pos]);  //toll pay option
   dfs(t_pos+1, bpool3+t_hire[t_pos], bpool2, bpool1 , cur_cost+2*t_cost[t_pos]);  //toll hire option
 
	if ( tot_bpool  >= t_hire[t_pos] )  //toll battle option
	{
		if (t_hire[t_pos] > bpool2 + bpool1 )  
        { 
            bpool3  =  tot_bpool - t_hire[t_pos];  
            bpool1 = bpool2 = 0;
        }
		else if (t_hire[t_pos] > bpool1 )
        {
             bpool2 = (bpool1+bpool2) - t_hire[t_pos];
             bpool1 = 0;
        }
		dfs(t_pos+1, 0,  bpool3 , bpool2, cur_cost); // note: pool3 is zero, pool3 becomes pool2 and pool2 as pool1
    }
}

int main()
{
    int i, TC;
    clock_t start, end;
    double cpu_time_used;
    
    printf("No.of.TC? ");      scanf("%d", &TC);
    start = clock();
    while( TC-- )
    {
    	scanf("%d", &N); 
    	for ( i = 0; i < N; ++i)
    	    scanf("%d %d", &t_hire[i], & t_cost  [i]);

        
    	dfs(0, 0, 0, 0, 0);
    	printf("\nMinCost= %d\n\n", min_cost );
    	min_cost = 1000000;  //some large number
     }
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("fun() took %f seconds to execute \n", cpu_time_used);
   getch();
	return 0;
}



****************************************************************************************************************************




****************topological sorting********************


#include<iostream>
using namespace std;
struct adjListNode{
	int dest;
	struct adjListNode * next;
};
struct adjList{
	struct adjListNode *head;
};
struct Graph{
	int V;
	struct adjList * array;
};
struct adjListNode * newadjListNode(int dest)
{
	struct adjListNode *newnode=new adjListNode();
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
}
struct Graph * createGraph(int v)
{
	struct Graph * g=new Graph();
	g->V=v;
	g->array=new adjList[v]();
	for(int i=0;i<v;i++)
	g->array[i].head=NULL;
	return g;
}
void addEdge(struct Graph *g,int u,int v)
{
	struct adjListNode *newnode=newadjListNode(v);
	newnode->next=g->array[u].head;
	g->array[u].head=newnode;
}
void printGraph(struct Graph *g)
{
	for(int i=0;i<g->V;i++)
	{
		struct adjListNode *itr=g->array[i].head;
		while(itr!=NULL)
		{
			cout<<"->"<<itr->dest;
			itr=itr->next;
		}
		cout<<endl;
	}
	
}
struct stackNode{
	int val;
	struct stackNode *next;
};
struct Stack{
	struct stackNode *top;
};
void push(struct Stack *s,int v)
{
	struct stackNode *newnode=new stackNode;
	newnode->val=v;
	newnode->next=NULL;
	newnode->next=s->top;
	s->top=newnode;
}
int pop(struct Stack *s )
{
	if(s->top==NULL)
	return -1;
	int val;
	val=s->top->val;
	s->top=s->top->next;
	return val;
}
int empty(struct Stack *s)
{
	if(s->top==NULL)
	return 1;
	return 0;
}
void topologicalsort(struct Graph *g, int u, bool visited[] , struct Stack *s)
{
	//cout<<"topological "<<u<<endl;
	visited[u]=1;
	struct adjListNode *itr=g->array[u].head;
	while(itr!=NULL)
	{
		int x=itr->dest;
		if(!visited[x])
		topologicalsort(g,x,visited,s);
		itr=itr->next;
	}
	push(s,u);
	//cout<<"returning "<<u<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int v,e,x,y;
		cin>>v>>e;
		struct Graph *g=createGraph(v);
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			addEdge(g,x-1,y-1);
		}
		//printGraph(g);
		bool visited[10000];
		for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}
		struct Stack *s=new Stack();
		s->top=NULL;
		for(int i=0;i<v;i++)
		if(!visited[i])
		topologicalsort(g,i,visited,s);
		while(!empty(s))
		{
			int x=pop(s);
			cout<<x+1<<" ";
		}
		cout<<endl;
	}
}



**********************************************************************************************************************************


*******************tunnel********************



#include<iostream>
#include<climits>
using namespace std;
int n,h,v,a[100][100],c[2],r[2],m[2],cost[100],allowed[100];
int mod(int x)
{
	if (x<0)
	return -x;
	else
	return x;
}
int calccost(int i)
{
	int mincost=100000;
	for(int j=0;j<=h;j++)
	{
		int cst=0;
		for(int k=0;k<j;k++)
		cst=cst+a[i][k]*c[0];
		for(int k=j;k<h;k++)
		cst=cst+a[i][k]*c[1];
		int addcost=0;
		if(j>(h-j))
		{
			//if(j-h+j-1>0)
			//addcost=r[0];
			addcost=(j-h+j-1)*r[0];
		}
		else if((h-j)>j)
		{
			//if(h-j-j-1>0)
			//addcost=r[1];
			addcost=(h-j-j-1)*r[1];
		}
		cst=cst+addcost;
		//cout<<cst<<endl;
		if(cst<mincost)
		{
			mincost=cst;
		}
	}
	return mincost;
}
int findcost(int last,int i,int x)
{
	//cout<<"inside("<<last<<","<<i<<","<<x<<")"<<endl;
	if(x==0)
	return 0;
	if(i>=v&&x>=1)
	return mod(INT_MAX);
	if(allowed[i]==1)
	{
		return findcost(last,i+1,x);
	}
	allowed[i]=1;
	allowed[i+1]=1;
	if(x==n)
	last=i;
	int cost1=+findcost(i,i+1,x-1);
	if(cost1!=INT_MAX)
	cost1=(m[0]*m[0]+m[1]*m[1])*(i-last)+cost[i]+cost1;
	allowed[i]=0;
	allowed[i+1]=0;
	int cost2=findcost(last,i+1,x);
	//cout<<"returning "<<min(cost1,cost2)<<endl;
	return min(cost1,cost2);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>h>>v;
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<h;j++)
			cin>>a[i][j];
		}
		cin>>c[0]>>r[0]>>m[0];
		cin>>c[1]>>r[1]>>m[1];
		for(int i=0;i<v;i++)
		{
			cost[i]=calccost(i);
			//cout<<cost[i]<<endl;
		}
		for(int i=0;i<v;i++)
		allowed[i]=0;
		int res=findcost(0,0,n);
		cout<<res<<endl;
	}
}



**********************************************************************************************************************************


****************worm hole*************************


#include <bits/stdc++.h>
using namespace std;
int v[100];
int n;
bool vis[100];
int cost[100];
int a[100][100];
int x[100];
int y[100];
int w[50];
int m;
void setmatrix()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=abs(x[j]-x[i])+abs(y[j]-y[i]);
        }
    }
    int j=1;
    for(int i=1;i<n-2;i+=2)
    {
        a[i][i+1]=w[j];
        a[i+1][i]=w[j];
        j++;
    }
}
int findmin()
{
    int mn=1000000;int k=-1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&mn>cost[i])
        {
            mn=cost[i];
            k=i;
        }
    }
    return k;
}
int mincost()
{
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
        cost[i]=1000000;
    }
    cost[0]=0;
    int z=1;
    while(z)
    {
        int j=findmin();
        vis[j]=true;
        if(j==n-1)
        return cost[j];
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&(a[j][i]+cost[j])<cost[i])
            {
                cost[i]=cost[j]+a[j][i];
            }
        }
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m;
        n=2*m+2;
        int i=0;
        cin>>x[i]>>y[i];
        i++;
        cin>>x[n-1]>>y[n-1];
        int j=1;
        while(i<n-1)
        {
            cin>>x[i]>>y[i++];
            cin>>x[i]>>y[i++];
            cin>>w[j++];
        }
        setmatrix();
        int ans=mincost();
        cout<<ans<<"\n";
    }
	//code
	return 0;
}



*************************************************************************************************************************************
	
	
	
