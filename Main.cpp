#include <string>
#include <cassert>  //assert
#include <iostream> //ostream
#include <functional> //less
#include <algorithm>
#include "csvstream.h"
#include "Team.h"
#include "Game.h"

using namespace std;

int main() {
    string homeTeam;
    string awayTeam;
    cout << "Enter Home Team: ";
    getline(cin, homeTeam);
    cout << endl;
    cout << "Enter Away Team: "; 
    getline(cin, awayTeam);
    csvstream adv("12-26_adv_stats.txt");
    csvstream stats("12-26_stats.txt");
    csvstream opp("12-26_opp_stats.txt");
    csvstream advOpp("12-26_opp_adv_stats.txt");
    csvstream advAway("12-26_adv_stats.txt");
    csvstream statsAway("12-26_stats.txt");
    csvstream oppAway("12-26_opp_stats.txt");
    csvstream advOppAway("12-26_opp_adv_stats.txt");
    map<string, string> statsRowHome;
    map<string, string> advRowHome;
    map<string, string> oppRowHome;
    map<string, string> advOppRowHome;
    int i = 0;
    while (i < 1 && stats >> statsRowHome) {
        if (statsRowHome["School"] == homeTeam) {
            i = 2;
        }
    }
    i = 0;
    while (i < 1 && adv >> advRowHome) {
        if (advRowHome["School"] == homeTeam) {
            i = 2;
        }
    }
    i = 0;
    while (i < 1 && opp >> oppRowHome) {
        if (oppRowHome["School"] == homeTeam) {
            i = 2;
        }
    }
    i = 0;
    while (i < 1 && advOpp >> advOppRowHome) {
        if (advOppRowHome["School"] == homeTeam) {
            i = 2;
        }
    }

    map<string, string> statsRowAway;
    map<string, string> advRowAway;
    map<string, string> oppRowAway;
    map<string, string> advOppRowAway;
    i = 0;
    while (i < 1 && statsAway >> statsRowAway) {
        if (statsRowAway["School"] == awayTeam) {
            i = 2;
        }
    }
    i = 0;
    while (i < 1 && advAway >> advRowAway) {
        if (advRowAway["School"] == awayTeam) {
            i = 2;
        }
    }
    i = 0;
    while (i < 1 && oppAway >> oppRowAway) {
        if (oppRowAway["School"] == awayTeam) {
            i = 2;
        }
    }
    i = 0;
    while (i < 1 && advOppAway >> advOppRowAway) {
        if (advOppRowAway["School"] == awayTeam) {
            i = 2;
        }
    }

    team home(statsRowHome, advRowHome, 
        oppRowHome, advOppRowHome);
    team away(statsRowAway, advRowAway,
        oppRowAway, advOppRowAway);

    game run(home, away);

    pair<string, int> result = run.runGame();

    if (result.first != "tie") {
        cout << result.first << " wins by " <<
            result.second << "." << endl;
    }
    else {
        cout << "It's a tie." << endl;
    }

    return 0;
}