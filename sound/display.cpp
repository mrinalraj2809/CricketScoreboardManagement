#include<iostream>
using namespace std;
typedef battingTeam.p[battingTeam.on_strike_batsman] BATSMEN;
typedef bowlingTeam.p[bowlingTeam.on_strike_bowler] BOWLER;
int main()/*displayInScoreboard(Team battingTeam, Team bowlingTeam )*/
{
  cout<<"                        **************************************************************************************************\n";
  cout<<"                        **************************************************************************************************\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **      BATTING TEAM      : "<<battingTeam.teamName<<"              BOWLING TEAM     : "<<bowlingTeam.teamName<<"                                                                          **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **      BATSMEN ON STRIKE : "<<battingTeam.p[battingTeam.on_strike_batsman].name_of_player<<"            BOWLER ON STRIKE : "<<bowlingTeam.p[bowlingTeam.on_strike_bowler].name_of_player<<"                                                        **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **      STRIKE RATE       : "<<battingTeam.p[battingTeam.on_strike_batsman].strike_rate_of_a_player<<"   ECONOMY RATE     : "<<bowlingTeam.p[bowlingTeam.on_strike_bowler].economy_rate_of_a_player<<"                                                                                     **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **      NUMBER OF RUNS    : "<<battingTeam.p[battingTeam.on_strike_batsman].no_of_runs_scored<<"         NO. RUNS GIVEN   : "<<bowlingTeam.p[bowlingTeam.on_strike_bowler].no_of_runs_given<<"                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **      NUMBER OF BALLS   : "<<battingTeam.p[battingTeam.on_strike_batsman].no_of_balls_played<<"        BALLS DELIVERED  : "<<bowlingTeam.p[bowlingTeam.on_strike_bowler].no_of_balls_delivered<<"                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **     TOTAL RUN          : "<<battingTeam.total_runs_scored_by_team<<"/"<<bowlingTeam.wicket_taken_by_Team"                                                                                        **\n";
  cout<<"                        **     CURRENT OVER       : "<<battingTeam.over_played_by_team<<"                                                                                         **\n";
  cout<<"                        **                                                                                              **\n";
  cout<<"                        **************************************************************************************************\n";
  cout<<"                        **************************************************************************************************\n";
}
