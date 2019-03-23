#include <iostream>
#include<ctime>
#include <cstring>
#include <cstdlib>
using namespace std;
class Player
{
	public:
	char name_of_player[26];
	int no_of_runs_scored;
	int no_of_runs_given,no_of_balls_played,no_of_balls_delivered;
	int extras,over_played;
	int no_of_wicket_taken;
	int extra;
	float strike_rate_of_a_player;

	Player()
	{
		strcpy(name_of_player,"");
		no_of_runs_scored=0;
		no_of_runs_given=0;
		no_of_balls_played=0;
		no_of_balls_delivered=0;
		extra=0;
		over_played=0;
		no_of_wicket_taken=0;
		strike_rate_of_a_player=0;
	}
	void setname()
	{
		cout<<"enter the player name ";
		cin>>name_of_player;

	}

};
class Team
{
	public:
	char teamName[10];
	Player p[16];
	int over_played_by_team;
	int wicket_taken_by_Team;
	int total_runs_scored_by_team;
	bool toss_won_by_team;
	int fall_of_wickets[10][2];    //runs vs wickets

	int on_strike_batsman;
	Team()
	{
		strcpy(teamName,"");
		over_played_by_team = 0;
		wicket_taken_by_Team = 0;
		total_runs_scored_by_team = 0;
		toss_won_by_team = 0;
		on_strike_batsman = 0;
		for(int i = 0; i< 10 ;i++)
		{
			for(int j=0;j< 2;j++)
			{
				fall_of_wickets[i][j]=0;
			}
		}
	}
	void setTeamname()
	{
		cout<<"Enter the Team name ";
		cin>>teamName;

	}
	//return true if given team choose to bat
	bool isBatting(Team t)
	{
		char choice[4];
		cout<<t.teamName<<":Would you like to Bat/Bowl first\t:-(Bat/Bowl)";
		cin>>choice;
		if(strcmp(choice,"Bat")==0)
			return true;
		else
			return false;
	}
	//return 0 for team 1 and 1 for team 2;
	int tossTime(Team t1, Team t2)
	{
		srand(time(NULL));
		int random;
		random=(rand()%2);
		cout<<"It toss time"<<endl;
		if(random==0)
		{

			cout<<t1.teamName<<"Will throw the coin"<<endl;
			random=(rand()%2);
			if(random ==0)
			{
				cout<<"Congratulations Team "<<t1.teamName<<" has won the toss";
				return 0;


			}
			else
			{
				cout<<"Congratulations Team "<<t2.teamName<<" has won the toss";
				return 1;
			}
		}
		else
		{
			cout<<t2.teamName<<"Will throw the coin"<<endl;
			random=(rand()%2);
			if(random ==0)
			{
				cout<<"Congratulations Team "<<t1.teamName<<" has won the toss";
				return 0;


			}
			else
			{
				cout<<"Congratulations Team "<<t2.teamName<<" has won the toss";
				return 1;
			}

		}
	}
	bool strike_changed(int runs)
	{
		switch(runs)
		{

			case 1:
			case 3:return true;
			case 0:
			case 2:
			case 4:
			case 6:return false;
			default:cout<<"Invalid Run";return;
		}
	}

	void inningsStarted(Team battingTeam,Team bowlingTeam)
	{

		int num_Of_Over_Match=3;char result;
		for(int i=0;i<num_Of_Over_Match*6;i++)
		{
			if(i==0)
			{
				cout<<"enter the result(0 to 6 )(w for wickets and e for extras)\t:";
				cin>>result;
				if(result>48 && result<57)
				{
					battingTeam.p[battingTeam.on_strike_batsman].no_of_runs_scored+=result-48;
					if(strike_changed(result-48)==true)
					{
						//to check strike change then increment run and wickets stats for team and player
						
					}



				}

			}
		}
		//to do 18 times loop if 3over match
		//at each ball update batsmen on strikes run and bowlers runs given also the TEAMS RUNS ,OVERS PLAYED,
		//if run scored is 1,3 strike changed else(0,4,6,2) strike unchanged
		//if wickets fall update bowlers wicket stats bring new batsmen on strike
	}

};

int main()
{
	Team t[2],t0;int over;
	cout<<"Enter the team format(Number of over the game should be played)\t:";
	cin>>over;
	t[0].setTeamname();
	t[1].setTeamname();
	int toss_won_by_team,toss_lost_by_team;
	bool tossWon_Team_Choose_Batting ;
	cout<<"please!Enter the playing  11 for team:"<<t[0].teamName<<endl;
	for(int i=0;i<11;i++)
	{
		cin>>t[0].p[i].name_of_player;
	}
	cout<<"Please!Enter the playing  11 for team:"<<t[1].teamName<<endl;
	for(int i=0;i<11;i++)
	{
		cin>>t[1].p[i].name_of_player;
	}
	// toss_won_by_team=Team::tossTime(t[0],t[1]);//0 for team1 and 1 for team2
		//to do team selecting for batting first
	toss_won_by_team=t0.tossTime(t[0],t[1]);
	if(toss_won_by_team==0)
		toss_lost_by_team=1;
	else
		toss_lost_by_team=0;
	//Innings started by "toss won by team"
	tossWon_Team_Choose_Batting=t0.isBatting(t[toss_won_by_team]);
	if(tossWon_Team_Choose_Batting)
	{

		t0.inningsStarted(t[toss_won_by_team],t[toss_lost_by_team]);
	}
	else
	{
		t0.inningsStarted(t[toss_lost_by_team],t[toss_won_by_team]);
	}
}
