#include<iostream>
using namespace std;

class Queens
{
	public:
		Queens(int size);
		bool is_solved() const;
		void print() const;
		bool unguarded(int col) const;
		void insert(int col);
		void remove(int col);
		int board_size;//女王最大数量 
	private:
		int count;//行号 
		bool queen_square[4][4];//棋盘	
};

void Queens::insert(int col)
{
	queen_square[count++][col]=true;
}

Queens::Queens(int size)
{
	board_size=size;
	count=0;
	for(int row=0;row<board_size;row++)
		for(int col=0;col<board_size;col++)
			queen_square[row][col]=false;
}

bool Queens::unguarded(int col) const
{
	int i;
	bool ok=true;
	for(i=0;ok&&i<count;i++)
		ok=!queen_square[i][col];
	for(i=1;ok&&count-i>=0&&col-i>=0;i++)
		ok=!queen_square[count-i][col-i];
	for(i=1;ok&&count-i>=0&&col+i<board_size;i++)
		ok=!queen_square[count-i][col+i];
	return ok;			
} 

void Queens::print()const
{
	for(int row=0;row<board_size;row++)
	{
		for(int col=0;col<board_size;col++)
		{
			if(queen_square[row][col])
				cout << "*";
			else
				cout << "0";	
		}
		cout << endl;		
	}
}

bool Queens::is_solved() const
{
	if(count==board_size)
		return true;
	else
		return false;	
}

void Queens::remove(int col)
{
	queen_square[--count][col]=false;
}

void solve_from(Queens &configuration)
{
	if(configuration.is_solved())
	{
		configuration.print();
		cout << endl;
	}	
	else
		for(int col=0;col<configuration.board_size;col++)
		{
			if(configuration.unguarded(col))
			{
				configuration.insert(col);
				solve_from(configuration);
				configuration.remove(col); 
			}
		}	
}

int main()
{
	Queens configuration(4);
	solve_from(configuration);
	return 0;
}
