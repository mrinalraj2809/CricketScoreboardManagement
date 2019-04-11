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
	int extras;
	float over_played;
	int no_of_wicket_taken;
	int extra;
	float economy_rate_of_a_player;
	float strike_rate_of_a_player;

	Player()
	{
		strcpy(name_of_player,"");
		no_of_runs_scored = 0;
		no_of_runs_given = 0;
		no_of_balls_played = 0;
		no_of_balls_delivered = 0;
		extra = 0;
		over_played = 0;
		no_of_wicket_taken = 0;
		strike_rate_of_a_player = 0;
		economy_rate_of_a_player = 0;
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
	float over_played_by_team;
	int wicket_taken_by_Team;
	int total_runs_scored_by_team;
	bool toss_won_by_team;
	int fall_of_wickets[10];    // wickets vs runs

	int on_strike_batsman;
	int far_end_batsman;
	int on_strike_bowler;
	Team()
	{
		strcpy(teamName,"");
		over_played_by_team = 0;
		wicket_taken_by_Team = 0;
		total_runs_scored_by_team = 0;
		toss_won_by_team = 0;
		on_strike_batsman = 0;
		far_end_batsman=1;
		on_strike_bowler=0;// set ffall_of_wickets[10][2]irst player as default bowler  , later to give option to user to choose their bowler
		fall_of_wickets[10]={0};
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
		if(strcmp(choice,"Bat")==0 ||strcmp(choice,"Bowl")==0)
		{
				if(strcmp(choice,"Bat")==0)
					return true;
				else
					return false;
		}
		else
		{
			cout<<"Invalid Input\nPlz re-enter your choice "<<endl;
			return isBatting(t);
		}
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
			case 5:
			case 3:return true;
			case 0:
			case 2:
			case 4:
			case 6:return false;
			default:cout<<"Invalid Run";
		}
		return NULL;
	}
	//To display details at the end of each over
	// batsmen on strike and non strike
	// strike rate
	// economy rate
	// current runrate runs per balls played
	void displayDataAtTheOverEnd(Team battingTeam , Team bowlingTeam/* arguments */)
	{
	  /* code Player data members
	  char name_of_player[26];
	  int no_of_runs_scored;
	  int no_of_runs_given,no_of_balls_played,no_of_balls_delivered;
	  int extras;
	  float over_played;
	  int no_of_wicket_taken;
	  int extra;
	  float economy_rate_of_a_player;
	  float strike_rate_of_a_player;
	  */
	  /* Team   data members
	  char teamName[10];
	  Player p[16];
	  float over_played_by_team;
	  int wicket_taken_by_Team;
	  int total_runs_scored_by_team;
	  bool toss_won_by_team;
	  int fall_of_wickets[10];    // wickets vs runs

	  int on_strike_batsman;
	  int far_end_batsman;
	  int on_strike_bowler;
	  */

	  cout << "Batsmen on Strike "<<battingTeam.p[battingTeam.on_strike_batsman].name_of_player << '\n';
	  cout << "Strike Rate "<< battingTeam.p[battingTeam.on_strike_batsman].strike_rate_of_a_player << "\n\n";
	  cout << "Batsmen far End " <<battingTeam.p[battingTeam.far_end_batsman].name_of_player << '\n';
	  cout << "Strike Rate "<< battingTeam.p[battingTeam.far_end_batsman].strike_rate_of_a_player << "\n\n";

	  cout << "Previous Bowler "<<bowlingTeam.p[bowlingTeam.on_strike_bowler].name_of_player << "\n";
	  cout << "Economy Rate " <<bowlingTeam.p[bowlingTeam.on_strike_bowler].economy_rate_of_a_player << "\n\n";

	  // Previous over runns

	}

	//func to display exclamatory message when 4 , 6 , w is entered
	void displayChowkaChakkaWicket(char run)
	{
		switch (run-48) {
			case 4:std::cout << "Thats Fantastic 4....." << '\n';break;
			case 6:std::cout << "Thats Hugeeeee  6....." << '\n';break;
			case 39:                                                                    // 39+48 =87 ('W')
			case 71:/*w*/cout << "Thats big blow to the Batting Team " << '\n';break;   // 71+48 =119 ('w')
			default:return;
		}
	}


	void inningsStarted(Team *battingTeam,Team *bowlingTeam,int num_Of_Over_Match)
	{

	  char result;
	  for(int i = 1;i <= num_Of_Over_Match * 6 ; i++)
	  {
	      cout<<"enter the result(0 to 6 )(w for wickets and e for extras)\t:";
	      cin>>result;   //Change the w to lower
				// to update balls played by on strike batsmen
				battingTeam->p[battingTeam->on_strike_batsman].no_of_balls_played++;
				if(result!='e' || result != 'e')
					bowlingTeam->p[bowlingTeam->on_strike_bowler].no_of_balls_delivered++;
	      displayChowkaChakkaWicket(result);

				//extra=0;   //to update if extras 'e' is input
				//no_of_wicket_taken=0;  if input is 'w' then update the wickets taken in the bowlingTeam player

				if (result=='w' || result == 'W')
				{
					//first display the player details after fall of his wickets
					(bowlingTeam->p[bowlingTeam->on_strike_bowler].no_of_wicket_taken)++;
					battingTeam->fall_of_wickets[bowlingTeam->wicket_taken_by_Team++]=battingTeam->total_runs_scored_by_team;
					battingTeam->on_strike_batsman = (battingTeam->on_strike_batsman > battingTeam->far_end_batsman ) ? battingTeam->on_strike_batsman + 1 : battingTeam->far_end_batsman + 1;
				}
	      if(result>=48 && result<=57)
	      {
	        battingTeam->p[battingTeam->on_strike_batsman].no_of_runs_scored+=result-48;
	        bowlingTeam->p[bowlingTeam->on_strike_bowler].no_of_runs_given+=result-48;
	        /*	no_of_runs_scored=0;
	            no_of_runs_given=0;
	            no_of_balls_played=0;
	            no_of_balls_delivered=0;

	            over_played=0;      //to be done after the end of each over or after match ends or wicket falls

	            strike_rate_of_a_player=0;*/    //runs vs ball in percent  also to be done after input is 'w'
	            //above is of class player
	        battingTeam->p[battingTeam->on_strike_batsman].no_of_balls_played++;
	        bowlingTeam->p[bowlingTeam->on_strike_bowler].no_of_balls_delivered++;

	          /*
	            over_played_by_team = 0;    //to be done after end of each
	            wicket_taken_by_Team = 0;
	            total_runs_scored_by_team = 0;
	            toss_won_by_team = 0;
	            on_strike_batsman = 0;
	            far_end_batsman=1;
	            fall_of_wickets[10];
	            */
	        battingTeam->total_runs_scored_by_team += (result - 48) ;
	        if(strike_changed(result-48)==true)
	        {
	          //to check strike change then increment run and wickets stats for team and player
	          //to swap the batsmen
	          battingTeam->on_strike_batsman=battingTeam->on_strike_batsman+battingTeam->far_end_batsman;
	          battingTeam->far_end_batsman=battingTeam->on_strike_batsman-battingTeam->far_end_batsman;
	          battingTeam->on_strike_batsman=battingTeam->on_strike_batsman-battingTeam->far_end_batsman;



	        }
	    	}
				if (i % 6 == 0 )
				{
					battingTeam->over_played_by_team++;
					battingTeam->p[battingTeam->on_strike_batsman].over_played=(battingTeam->p[on_strike_batsman].no_of_balls_played*1.0)/6;//over played by a batsmen
					bowlingTeam->p[bowlingTeam->on_strike_bowler].over_played++;//update the ball delivered
					//strike rate of batsmen after each delivery
					battingTeam->p[battingTeam->on_strike_batsman].strike_rate_of_a_player=(battingTeam->p[battingTeam->on_strike_batsman].no_of_runs_scored / (battingTeam->p[battingTeam->on_strike_batsman].no_of_balls_played ))*100;
					battingTeam->p[battingTeam->far_end_batsman].strike_rate_of_a_player=(battingTeam->p[battingTeam->far_end_batsman].no_of_runs_scored / (battingTeam->p[battingTeam->far_end_batsman].no_of_balls_played ))*100;
					//economy rate of bowler after each delivery
					bowlingTeam->p[bowlingTeam->on_strike_bowler].economy_rate_of_a_player=(bowlingTeam->p[bowlingTeam->on_strike_bowler].no_of_runs_given*1.0/bowlingTeam->p[bowlingTeam->on_strike_bowler].no_of_balls_delivered)*100;
					//to swap the batsmen at the end of over
					battingTeam->on_strike_batsman=battingTeam->on_strike_batsman+battingTeam->far_end_batsman;
					battingTeam->far_end_batsman=battingTeam->on_strike_batsman-battingTeam->far_end_batsman;
					battingTeam->on_strike_batsman=battingTeam->on_strike_batsman-battingTeam->far_end_batsman;
					displayDataAtTheOverEnd(*battingTeam,*bowlingTeam);
				}


	  //to do 18 times loop if 3over match
	  //at each ball update batsmen on strikes run and bowlers runs given also the TEAMS RUNS ,OVERS PLAYED,
	  //if run scored is 1,3 strike changed else(0,4,6,2) strike unchanged
	  //if wickets fall update bowlers wicket stats bring new batsmen on strike
		}
	}


};

int main()
{
	Team t[2],t0;int over;
	int innings_1_batting_team;
	int innings_2_batting_team;
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

		innings_1_batting_team=toss_won_by_team;
		t0.inningsStarted(&t[toss_won_by_team],&t[toss_lost_by_team],over);
	}
	else
	{
		innings_1_batting_team=toss_lost_by_team;
		t0.inningsStarted(&t[toss_lost_by_team], &t[toss_won_by_team],over);
	}
	//Innings 1 stores the 0 or 1 which mean we can get the no. of runs scored in innings 1
	cout<<"Total runs required to win the match \t:"<<t[innings_1_batting_team].total_runs_scored_by_team + 1<<endl;

	//After innnings is over we hv to display

}
