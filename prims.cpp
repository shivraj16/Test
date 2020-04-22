
//Comment

#include<iostream>
using namespace std;

int findp(int parent[10],int k)
{
	if(parent[k]==k)
	return k;
	
	else
	return findp(parent,parent[k]);
}

int iscycle(int s,int d)
{
	if(s==d)
	return 1;
	
	else
	return 0;
}
void prims(int b[10][3],int e,int v)
{
	int c[v-1][3];
	int vis[v],parent[v],i,j,k;
	int ce[e];
	int mn,sp,dp;
	for(i=0;i<v;i++)
	{
		vis[i]=0;
		parent[i]=i;
	}
	for(i=0;i<e;i++)
	{
	  ce[i]=0;
	}
	
	k=0;
	for(i=0;i<v-1;i++)
	{
		if(i==0)
		{
			c[0][0]=b[0][0];
			c[0][1]=b[0][1];
			c[0][2]=b[0][2];
			k++;
			ce[0]=1;
			vis[c[0][0]]=1;
			vis[c[0][1]]=1;
			
			sp=findp(parent,b[0][0]);
			dp=findp(parent,b[0][1]);
			parent[dp]=sp;
		}
		else
		{
			for(int o=1;o<e;o++)
			{
			  if(vis[b[o][0]]==1||vis[b[o][1]]==1)
			  {
			  	if(ce[o]==0)
			  	{
			  			sp=findp(parent,b[o][0]);
			            dp=findp(parent,b[o][1]);
			          if(!iscycle(sp,dp))
			          {
			          	ce[o]=1;
			          	parent[dp]=sp;
			          	c[k][0]=b[o][0];
						c[k][1]=b[o][1];
						c[k][2]=b[o][2];
					
						vis[c[k][0]]=1;
						vis[c[k][1]]=1;
						k++;
					  }
				  }
			  }
			  
			}
			
		}
	}
	cout<<"The minimum spanning tree is:\n";
	
	for(i=0;i<v-1;i++)
	{
		cout<<c[i][0]<<"  "<<c[i][1]<<"  "<<c[i][2]<<endl;
	}
}

int main()
{
	int v,e;
	cout<<"Enter the number of vertices and edges in the graph:\n";
	cin>>v>>e;
	int b[e][3];
	int a[v][v];
	
	int i,j,k;
	for(i=0;i<e;i++)
	{
		cout<<"Enter the start and end vertex of the edge:";
		cin>>b[i][0]>>b[i][1];
		cout<<"Enter the weight of the edge:";
		cin>>b[i][2];
	}
	
	
		for(i=0;i<e;i++)
	{
		cout<<b[i][0]<<"  "<<b[i][1]<<"  "<<b[i][2]<<endl;
		
	}
	
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==j)
			{
				a[i][j]=0;
			}
			else
			{
				a[i][j]=999;
			}
		}
	}
	for(i=0;i<e;i++)
	{
		a[b[i][0]][b[i][1]]=a[b[i][1]][b[i][0]]=b[i][2];
	}
	
	cout<<"\n The adjacency matrix of the graph is :\n\n";
	
		for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
	int t3,t1,t2;
	cout<<endl;
	for(i=0;i<e;i++)
	{
		for(j=0;j<e-1;j++)
		{
			if(b[j][2]>b[j+1][2])
			{
				t1=b[j+1][0];
				t2=b[j+1][1];
				t3=b[j+1][2];
				
		        b[j+1][0]=b[j][0];
				b[j+1][1]=b[j][1];
				b[j+1][2]=b[j][2];
				
				b[j][0]=t1;
				b[j][1]=t2;
				b[j][2]=t3;
			}
		}
	}
	
	cout<<"The sorted edges are:\n";
	
	for(i=0;i<e;i++)
	{
		cout<<b[i][0]<<"  "<<b[i][1]<<"  "<<b[i][2]<<endl;
		
	}
	prims(b,e,v);
}
