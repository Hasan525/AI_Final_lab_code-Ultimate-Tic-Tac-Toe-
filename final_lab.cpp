 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
char board[4][4][4][4];
int next_r,next_c;
map<pair<int,int>,int>mp;
bool gameOver = false;
int myWinCount =0, oponentWinCount =0;



bool checkAnyWin(int r1,int c1, char ch)
{
    int myMove=0;
    //RowWiseCheck
    for(int i=1; i<4; i++)
    {
        myMove=0;
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][i][j]==ch)
            {
                myMove++;
            }
        }
        if(myMove ==3)
        {
            return true;
        }
    }

    //ColumnWiseCheck
    for(int i=1; i<4; i++)
    {
        myMove=0;
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][j][i]==ch)myMove++;
        }
        if(myMove ==3)
        {
            return true;
        }
    }

    //DiagonalWise
    myMove=0;
    for(int i=1; i<4; i++)
    {
        if(board[r1][c1][i][i]==ch)myMove++;
    }

    if(myMove == 3)
    {
        return true;
    }

    int i=3,j=1;
    myMove=0;
    while(i>=1)
    {
        if(board[r1][c1][i][j]==ch)myMove++;
        i--;
        j++;

    }

    if(myMove ==3)
    {
        return true;
    }


    return false;
}

bool validSearchMove(int r1,int c1)
{
    int myMove=0,hisMove=0;
    //RowWiseCheck
    for(int i=1; i<4; i++)
    {
        myMove=0;
        hisMove=0;
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][i][j]=='*')hisMove++;
            else if(board[r1][c1][i][j]=='&')myMove++;
        }
        if(hisMove==2 && myMove ==0) return false;
    }

    //ColumnWiseCheck
    for(int i=1; i<4; i++)
    {
        myMove=0;
        hisMove=0;
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][i][j]=='*')hisMove++;
            else if(board[r1][c1][j][i]=='&')myMove++;
        }
        if(hisMove==2 && myMove ==0) return false;
    }

    //DiagonalWise
    myMove=0;
    hisMove=0;
    for(int i=1; i<4; i++)
    {
        if(board[r1][c1][i][i]=='*')hisMove++;
        else if(board[r1][c1][i][i]=='&')myMove++;
    }
    if(hisMove==2 && myMove ==0) return false;

    int i=3,j=1;
    while(i>=1)
    {
        if(board[r1][c1][i][j]=='*')hisMove++;
        else if(board[r1][c1][i][j]=='&')myMove++;
        i--;
        j++;
    }
    if(hisMove==2 && myMove ==0) return false;


    return true;
}


bool checkAnyWinStage(int r1,int c1,char ch)
{
    int myMove=0,hisMove=0;
    int temp_i=0,temp_j=0;
    //RowWiseCheck
    for(int i=1; i<4; i++)
    {
        myMove=0,temp_i=0;
        hisMove=0,temp_j=0;
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][i][j]==ch)
            {
                myMove++;
            }
            else if(board[r1][c1][i][j]!='?')
            {
                hisMove++;
            }
            else
            {
                temp_i=i;
                temp_j=j;
            }
        }
        if(hisMove==0 && myMove ==2)
        {
            next_r=temp_i;
            next_c=temp_j;
            return true;
        }
    }

    //ColumnWiseCheck
    for(int i=1; i<4; i++)
    {
        myMove=0,temp_i=0;
        hisMove=0,temp_j=0;
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][j][i]==ch)myMove++;
            else if(board[r1][c1][j][i]!='?')
            {
                hisMove++;
            }
            else
            {
                temp_i=i;
                temp_j=j;
            }
        }
        if(hisMove==0 && myMove ==2)
        {
            next_r=temp_i;
            next_c=temp_j;
            return true;
        }
    }

    //DiagonalWise
    myMove=0,temp_i=0;
    hisMove=0,temp_j=0;
    for(int i=1; i<4; i++)
    {
        if(board[r1][c1][i][i]==ch)myMove++;
        else if(board[r1][c1][i][i]!='?')
        {
            hisMove++;
        }
        else
        {
            temp_i=i;
            temp_j=i;
        }
    }

    if(hisMove==0 && myMove ==2)
    {
        next_r=temp_i;
        next_c=temp_j;
        return true;
    }

    int i=3,j=1;
    myMove=0,temp_i=0;
    hisMove=0,temp_j=0;
    while(i>=1)
    {
        if(board[r1][c1][i][j]==ch)myMove++;
        else if(board[r1][c1][i][j]!='?')
        {
            hisMove++;
        }
        else
        {
            temp_i=i;
            temp_j=j;
        }
        i--;
        j++;

    }

    if(hisMove==0 && myMove ==2)
    {
        next_r=temp_i;
        next_c=temp_j;
        return true;
    }


    return false;
}

bool checkAltimateBoardGame(int val)
{
    int cnt = 0;
    for(int i=1;i<4;i++)
    {
        cnt = 0;
        for(int j=1;j<4;j++)
        {
            if(mp[{i,j}]==val) cnt++;
        }
        if(cnt==3) return true;
    }


    for(int i=1;i<4;i++)
    {
        cnt = 0;
        for(int j=1;j<4;j++)
        {
            if(mp[{j,i}]==val) cnt++;
        }
        if(cnt==3) return true;
    }

    cnt = 0;
    for(int i=1;i<4;i++)
    {
        if(mp[{i,i}]==val) cnt++;
    }
    if(cnt==3) return true;


    cnt = 0;
    int i=3,j=1;
    while(i>=1)
    {
        if(mp[{i,j}]==val) cnt++;
        j++;
        i--;
    }
    if(cnt==3) return true;
}

bool checkIsGameOver()
{
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(mp[ {i,j}]==0)
            {
                for(int k=1;k<4;k++)
                {
                    for(int l=1;l<4;l++)
                    {
                        if(board[i][j][k][l]=='?') return false;
                    }
                }
            }
        }
    }
    return true;
}


void anyRandomMove()
{
    if(checkIsGameOver())
    {
        gameOver= true;
        return;
    }

    if(checkAltimateBoardGame(1) || checkAltimateBoardGame(2))
    {
        gameOver= true;
        return;
    }

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(mp[ {i,j}]==0 && checkAnyWinStage(i,j,'&'))
            {
                mp[ {i,j}]=1;
                myWinCount++;
                board[i][j][next_r][next_c]='&';
                cout<<i<<" "<<j<<" "<<next_r<<" "<<next_c<<endl;
                return ;
            }
        }
    }

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            for(int k=1; k<4; k++)
            {
                for(int l=1; l<4; l++)
                {
                    if(board[i][j][k][l]=='?' && mp[ {i,j}]==0)
                    {
                        if(validSearchMove(k,l))
                        {
                            board[i][j][k][l]='&';
                            cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                            next_r=k;
                            next_c=l;
                            return;
                        }
                    }
                }
            }
        }
    }

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(mp[ {i,j}]==0 && checkAnyWinStage(i,j,'*'))
            {
                board[i][j][next_r][next_c]='&';
                cout<<i<<" "<<j<<" "<<next_r<<" "<<next_c<<endl;
                return ;
            }
        }
    }

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            for(int k=1; k<4; k++)
            {
                for(int l=1; l<4; l++)
                {
                    if(board[i][j][k][l]=='?' && mp[ {i,j}]==0)
                    {
                        board[i][j][k][l]='&';
                        cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                        next_r=k;
                        next_c=l;
                        return;
                    }
                }
            }
        }
    }
}

void initializ()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                for(int l=0; l<4; l++)
                {
                    board[i][j][k][l]='?';
                }
            }
        }
    }
}
void print_sub_grid(ll x, ll y, ll z)
{
    for(ll i=0 ; i<3 ; i++) cout<<board[x+1][y+1][z+1][i+1]<<" ";
    cout<<"   ";
}


void printBoard()
{
    // first row main grid
    print_sub_grid(0,0,0);
    print_sub_grid(0,1,0);
    print_sub_grid(0,2,0);
    cout<<endl;
    print_sub_grid(0,0,1);
    print_sub_grid(0,1,1);
    print_sub_grid(0,2,1);
    cout<<endl;
    print_sub_grid(0,0,2);
    print_sub_grid(0,1,2);
    print_sub_grid(0,2,2);
    cout<<endl;
    cout<<endl;
    // second row main grid
    print_sub_grid(1,0,0);
    print_sub_grid(1,1,0);
    print_sub_grid(1,2,0);
    cout<<endl;
    print_sub_grid(1,0,1);
    print_sub_grid(1,1,1);
    print_sub_grid(1,2,1);
    cout<<endl;
    print_sub_grid(1,0,2);
    print_sub_grid(1,1,2);
    print_sub_grid(1,2,2);
    cout<<endl;
    cout<<endl;

    // third row main grid
    print_sub_grid(2,0,0);
    print_sub_grid(2,1,0);
    print_sub_grid(2,2,0);
    cout<<endl;
    print_sub_grid(2,0,1);
    print_sub_grid(2,1,1);
    print_sub_grid(2,2,1);
    cout<<endl;
    print_sub_grid(2,0,2);
    print_sub_grid(2,1,2);
    print_sub_grid(2,2,2);
    cout<<endl;
    cout<<endl;
}


void serachAndTurn(int r1,int c1)
{
    if(mp[ {r1,c1}]==1)
    {
        anyRandomMove();
        return;
    }

    if(checkAnyWinStage(r1,c1,'&') && mp[ {r1,c1}]==0)
    {
        mp[ {r1,c1}]=1;
        myWinCount++;
        board[r1][c1][next_r][next_c]='&';
        cout<<r1<<" "<<c1<<" "<<next_r<<" "<<next_c<<endl;
        return ;
    }


    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][i][j]=='?')
            {
                if(validSearchMove(i,j))
                {
                    board[r1][c1][i][j]='&';
                    cout<<r1<<" "<<c1<<" "<<i<<" "<<j<<endl;
                    next_r=i;
                    next_c=j;
                    return;
                }
            }
        }
    }

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(board[r1][c1][i][j]=='?')
            {
                board[r1][c1][i][j]='&';
                cout<<r1<<" "<<c1<<" "<<i<<" "<<j<<endl;
                next_r=i;
                next_c=j;
                return;
            }
        }
    }
}




int main()
{
    initializ();
    cout<<"Board index number 1 to 3"<<endl<<endl;
    printBoard();
    int r1,c1,r2,c2;
    cout<<"Enter your first move :"<<endl;
    cout<<"Please enter big board row column"<<endl;
    cin>>r1>>c1;
    cout<<"Please enter small board row column"<<endl;
    cin>>r2>>c2;
    board[r1][c1][r2][c2]='*';
    printBoard();
    next_r=r2;
    next_c=c2;

    int tnext_r=r2;
    int tnext_c=c2;
    while(!gameOver)
    {
        if(gameOver)
        {
            cout<<"Game over"<<endl;
            break;
        }
        serachAndTurn(next_r,next_c);
        printBoard();
        while(mp[ {next_r,next_c}]!=0)
        {
            cout<<"Please enter big board row column"<<endl;
            cin>>r1>>c1;
            next_r=r1;
            next_c=c1;
        }
        if(mp[ {next_r,next_c}]==0)
        {
            cout<<"Please enter small board row column"<<endl;
            while(1)
            {
                cin>>r2>>c2;
                if(board[next_r][next_c][r2][c2]=='?')
                {
                    break;
                }
                cout<<"Enter your valid turn :"<<endl;
            }
        }
        cout<<next_r<<" "<<next_c<<" "<<r2<<" "<<c2<<endl;
        board[next_r][next_c][r2][c2]='*';

        if(checkAnyWin(next_r,next_c,'*'))
        {
            oponentWinCount++;
            mp[ {next_r,next_c}]=2;
        }
        printBoard();
        next_r=r2;
        next_c=c2;

    }


    if(checkAltimateBoardGame(1))
    {
        cout<<"I am the Winner"<<endl;
    }
    else if(checkAltimateBoardGame(2))
    {
        cout<<"Opponent is Winner"<<endl;
    }
    else
    {
        cout<<"Game draw"<<endl;
    }

}
