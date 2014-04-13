class Solution {
public:
    void solve(vector<vector<char>> &board) {

    	class pos{
    	public:
    		int row;
    		int col;
    	};

    	int numRows= board.size(),dfsCount;
    	if(numRows==0)
    		return ;
		std::stack<pos> dfsStack;
    	int numCols= board[0].size(),i,j;

    	bool visited[numRows][numCols];
    	for(i=0;i<numRows;i++)
    	for(j=0;j<numCols;j++)
    		visited[i][j]=false;
    	vector<bool> dfs;
    	for(i=0;i<numRows;i++)
    	{
    		for(j=0;j<numCols;j++)
    		{
    			if(board[i][j]!='X' && !visited[i][j])
    				{
    					pos node,node1;
    					node.row=i;
    					node.col=j;

    					dfsStack.push(node);
    					bool isNotBounded=false;
    					while(!dfsStack.empty())
    					{
    						node1=dfsStack.top();
    						dfsStack.pop();
    						if(visited[node1.row][node1.col]||node1.row<0 || node1.row>=numRows||node1.col<0|node1.col>=numCols)
    							continue;
    						if(board[node1.row][node1.col]=='X')
    							continue;
    						visited[node1.row][node1.col]=true;

    						if(!(node1.row>0 && node1.row<numRows-1 && node1.col>0 && node1.col<numCols-1))
    							isNotBounded=true;
    						node1.col--;
							dfsStack.push(node1);
							node1.col+=2;
							dfsStack.push(node1);
							node1.col--;
							node1.row--;
							dfsStack.push(node1);
							node1.row+=2;
							dfsStack.push(node1);
    					}
   						
   						dfs.push_back(!isNotBounded);
    				}
    		}
    	}
	for(i=0;i<numRows;i++)
    	for(j=0;j<numCols;j++)
    		visited[i][j]=false;
    	dfsCount=0;
    for(i=0;i<numRows;i++)
    	{
    		for(j=0;j<numCols;j++)
    		{
    			if(board[i][j]!='X' && !visited[i][j])
    				{
    					pos node,node1;
    					node.row=i;
    					node.col=j;

    					dfsStack.push(node);
    					bool isNotBounded=false;
    					while(!dfsStack.empty())
    					{
    						node1=dfsStack.top();
    						dfsStack.pop();
    						if(visited[node1.row][node1.col]||node1.row<0 || node1.row>=numRows||node1.col<0|node1.col>=numCols)
    							continue;
    						if(board[node1.row][node1.col]=='X')
    							continue;
    						visited[node1.row][node1.col]=true;
    						if(dfs[dfsCount])
    						board[node1.row][node1.col]='X';
    						node1.col--;
							dfsStack.push(node1);
							node1.col+=2;
							dfsStack.push(node1);
							node1.col--;
							node1.row--;
							dfsStack.push(node1);
							node1.row+=2;
							dfsStack.push(node1);
    					}
   						dfsCount++;
   					}
    		}
    	}	
        
    }

  };