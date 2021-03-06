#ifndef _mhshlSpider
#define _mhshlSpider

#include <vector>
#include <string>


// Will append the zero to the beginning of a number to bring it to two places.
std::string twoPlace(int num);

class ScoringEvent{
public:
	ScoringEvent();
	ScoringEvent(std::string gID, std::string tID, int gs, int a1, int a2, int per, int sec);
	void printString();
	void printHeading();
	std::string gameID; // Format for this is MMDDYY-HomeAbbr. For example, 120515-QCB
	std::string teamID; // The same shorthand team identifier.
	int scorer;
	int assist1;
	int assist2;
	int period; // 1-3 normal, 4 OT, 5 SO
	int time; // Seconds remaining in the period.
	int powerPlay;
};

class PenaltyEvent{
public:
	PenaltyEvent();
	PenaltyEvent(std::string gID, std::string tID, int pl, int dur, int per, int sec, std::string charge);
	void printString();
	void printHeading();
	std::string gameID;
	std::string teamID;
	int player;
	int duration;
	int period;
	int time;
	int timeRemaining;
	int goalsWhile;
	bool scoredOn;
	std::string offense;
};

class GoaliePerformance{
public:
	GoaliePerformance();
	GoaliePerformance(std::string gID, std::string tID, int pl, int sec, int ga, int sa);
	std::string gameID;
	std::string teamID;
	int player;
	int seconds;
	int goalsAgainst;
	int shotsAgainst;
	int saves;

	void printHeader();
	void printString();
};

class Team{
public:
	Team();
	Team(std::string abbr, std::string n, std::string c, int identifier);
	void printHeading();
	void printString();
	std::string abbreviation;
	std::string name;
	std::string city;
	int pointstreakID;
	int gamesPlayed;
	int wins;
	int losses;
	int overtimeLosses;
	int shootoutLosses;
	int points;
	int goalsFor;
	int goalsAgainst;
	int penaltyMinutes;
	int winLossStreak; // Win streaks positive, losing streak negative.
};

class Player{
public:
	Player();
	Player(std::string tID, std::string name, int identifier, int num);
	void printHeading();
	void printString();
	void printGoalieHeading();
	void printGoalieString();
	std::string teamID; // Abbreviation
	std::string name;
	int pointstreakID;
	int jerseyNumber;
	int gamesPlayed;
	int goals;
	int assists;
	int powerPlayGoals;
	int shortHandedGoals;
	int penaltyMinutes;
	int goalStreak;
	int pointStreak;
	bool goalie;
	int minutesPlayed;
	int shots;
	int goalsAgainst;
	float goalsAgainstAverage;
	int saves;
	float savePercentage;
};

/*
Game is a basic class to hold information about, well, a game.
*/

class Game{
public:
	Game();
	Game(int m, int d, int y, int st, std::string home, std::string away, int t, int num);
	void printString();
	void printHeading();
	// Date related stuff

	std::string id;

	int month;
	int day;
	int year;
	int startTime; // In minutes

	std::string homeTeam;
	std::string awayTeam;

	int homeScore;
	int awayScore;

	int homeShots;
	int awayShots;

	int period; // 1-3 self explanatory. 4 is OT. 5 is SO.
	int time; // Time is in seconds remaining in the period. -1 signifies a final. -2 F-OT. -3 F-SO.
	int number;

	bool rosterTaken;
};


/*
League is the base container class for all the teams, games, and players.
*/
class League{
public:
	League(int pL, bool var, int s);
	bool varsity;
	bool addTeam(Team *team);
	bool addPlayer(Player *player);
	void addPenaltyEvent(PenaltyEvent *penaltyEvent);
	void addScoringEvent(ScoringEvent *scoringEvent);
	bool addGame(Game *game);

	void setGoaliePerformance(std::string gID, std::string tID, int pl, int sec, int ga, int sa);

	void updateGameTime(std::string gID, int per, int sec);
	void updatePenalties(std::string gID, int dT);
	int powerPlayGoal(std::string gID, std::string tID);
	void removeOldestPenalty(std::string gID, std::string tID);
	Game* getGame(std::string gID);
	Player* getPlayer(std::string tID, int num);
	Player* getPlayer(int id);
	PenaltyEvent* getPenaltyEvent(std::string gID, std::string tID, int player, int per, int time, int duration, std::string penalty);
	ScoringEvent* getScoringEvent(std::string gID, int per, int time);
	Team* getTeam(std::string tID);
	Team* getTeam(int num);

	int periodLength;
	int season;

	std::vector<Game> games;
	std::vector<Team> teams;
	std::vector<Player> players;
	std::vector<ScoringEvent> goals;
	std::vector<PenaltyEvent> penalties;
	std::vector<GoaliePerformance> goaliePerformances;
};


#endif
