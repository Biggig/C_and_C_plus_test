#include<iostream>
using namespace std;

static int numOfPersons=0;

struct person
{
	int id;
	int friends[100];
	int numOfFriends;
	person()
	{
		id=numOfPersons;
		numOfFriends=0;
		numOfPersons++;
	}
}; 

class group
{
	public:
		group(int num)
		{
			property=num;
			numOfMembers=0;
		}
		void addMember(person &p)
		{
			member[numOfMembers].id=p.id;
			member[numOfMembers].numOfFriends=0;
			numOfMembers++;
			if(property==1)
			{
				int in1;
				for(in1=0;in1<numOfMembers-1;in1++)
				{
					if(member[in1].id!=-1)
					makeFriend(member[in1],member[numOfMembers-1]);
				}
			}
		}
		void deleteMember(person &p)
		{
			int in1;
			int mm=0;
			for(in1=0;in1<numOfMembers;in1++)
			{
				if(member[in1].id==p.id)
				{
					mm=in1;
					break;
				}
			}
			for(in1=0;in1<numOfMembers;in1++)
			{
				if(in1!=mm&&member[in1].id!=-1)
				breakRelation(member[in1],member[mm]);
			}
			member[mm].id=-1;
		}
		void makeFriend(person &p1,person &p2)
		{
			int m1;
			int m2;
			int in1;
			for(in1=0;in1<numOfMembers;in1++)
			{
				if(member[in1].id==p1.id)
				m1=in1;
				else if(member[in1].id==p2.id)
				m2=in1;
			}
			member[m1].friends[member[m1].numOfFriends]=p1.id;
			member[m1].numOfFriends++;
			member[m2].friends[member[m2].numOfFriends]=p2.id;
			member[m2].numOfFriends++;
		}
		void breakRelation(person &p1,person &p2)
		{
			int m1;
			int m2;
			int in1;
			for(in1=0;in1<numOfMembers;in1++)
			{
				if(member[in1].id==p1.id)
				m1=in1;
				else if(member[in1].id==p2.id)
				m2=in1;
			}
			for(in1=0;in1<member[m1].numOfFriends;in1++)
			{
				if(member[m1].friends[in1]==p2.id)
				{
					member[m1].friends[in1]=-1;
					break;
				}
			}
			for(in1=0;in1<member[m2].numOfFriends;in1++)
			{
				if(member[m2].friends[in1]==p1.id)
				{
					member[m2].friends[in1]=-1;
					break;
				}	
			}
		}
		void displayGroup()
		{	
			int in1;
			for(in1=0;in1<numOfMembers;in1++)
			{
				if(member[in1].id!=-1)
				{
					cout << "Person_" << member[in1].id << ":";
					int in2;
					for(in2=0;in2<member[in1].numOfFriends;in2++)
					{
						if(/*member[in1].friends[in2]!=-1&&*/in2!=member[in1].numOfFriends-1)
						cout << member[in1].friends[in2] << ", ";
						else if(/*member[in1].friends[in2]!=-1&&*/in2==member[in1].numOfFriends-1)
						cout << member[in1].friends[in2] << endl;
					}
				}
			}		
		}
	private:
		person member[100];
		int property;
		int numOfMembers;	
}; 
