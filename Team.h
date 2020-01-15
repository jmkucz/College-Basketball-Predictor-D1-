#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <cassert>  //assert
#include <iostream> //ostream
#include <functional> //less
#include <algorithm>
#include "csvstream.h"

using namespace std;

class team {
public:
    team(map<string, string> stats, map<string, string> advStats,
        map<string, string> oppStats, map<string, string> advOppStats) {
        name = stats["School"];
        wins = stod(stats["W-O"]);
        losses = stod(stats["L-O"]);
        games = stod(stats["G-O"]);
        WLPercentage = stod(stats["W-L%-O"]);
        confWins = stod(stats["W-C"]);
        confLosses = stod(stats["L-C"]);
        confPercentage = confWins / (confLosses + confWins);
        homeWins = stod(stats["W-H"]);
        homeLosses = stod(stats["L-H"]);
        homePercentage = homeWins / (homeWins + homeLosses);
        awayWins = stod(stats["W-A"]);
        awayLosses = stod(stats["L-A"]);
        awayPercentage = awayWins / (awayWins + awayLosses);
        SOS = stod(stats["SOS"]);
        SRS = stod(stats["SRS"]);
        pointsPerGame = stod(stats["Tm."]) / games;
        pointsAgainstPerGame = stod(stats["Opp."]) / games;
        FGPerGame = stod(stats["FG"]) / games;
        FGAPerGame = stod(stats["FGA"]) / games;
        FGPercentage = stod(stats["FG%"]);
        threesPerGame = stod(stats["3P"]);
        threesAPerGame = stod(stats["3PA"]) / games;
        threePercentage = stod(stats["3P%"]);
        FTPerGame = stod(stats["FT"]);
        FTAPerGame = stod(stats["FTA"]) / games;
        FTPercentage = stod(stats["FT%"]);
        offRebPerGame = stod(stats["ORB"]) / games;
        totRebPerGame = stod(stats["TRB"]) / games;
        assistPerGame = stod(stats["AST"]) / games;
        stealsPerGame = stod(stats["STL"]) / games;
        blocksPerGame = stod(stats["BLK"]) / games;
        turnoversPerGame = stod(stats["TOV"]) / games;
        personalFoulsPerGame = stod(stats["PF"]) / games;

        oppPointsPerGame = stod(oppStats["Tm."]) / games;
        oppPointsAgainstPerGame = stod(oppStats["Opp."]);
        oppFGPerGame = stod(oppStats["FG"]) / games;
        oppFGAPerGame = stod(oppStats["FGA"]) / games;
        oppFGPercentage = stod(oppStats["FG%"]);
        oppThreesPerGame = stod(oppStats["3P"]);
        oppThreesAPerGame = stod(oppStats["3PA"]) / games;
        oppThreePercentage = stod(oppStats["3P%"]);
        oppFTPerGame = stod(oppStats["FT"]);
        oppFTAPerGame = stod(oppStats["FTA"]) / games;
        oppFTPercentage = stod(oppStats["FT%"]);
        oppOffRebPerGame = stod(oppStats["ORB"]) / games;
        oppTotRebPerGame = stod(oppStats["TRB"]) / games;
        oppAssistPerGame = stod(oppStats["AST"]) / games;
        oppStealsPerGame = stod(oppStats["STL"]) / games;
        oppBlocksPerGame = stod(oppStats["BLK"]) / games;
        oppTurnoversPerGame = stod(oppStats["TOV"]) / games;
        oppPersonalFoulsPerGame = stod(oppStats["PF"]) / games;

        pace = stod(advStats["Pace"]);
        ORtg = stod(advStats["ORtg"]);
        Ftr = stod(advStats["FTr"]);
        ThreeAttemptRate = stod(advStats["3PAr"]);
        trueShooting = stod(advStats["TS%"]);
        totalReboundingPercentage = stod(advStats["TRB%"]);
        assistPercentage = stod(advStats["AST%"]);
        stealPercentage = stod(advStats["STL%"]);
        blockPercentage = stod(advStats["BLK%"]);
        effectiveFG = stod(advStats["eFG%"]);
        turnoverPercentage = stod(advStats["TOV%"]);
        ORebPercentage = stod(advStats["ORB%"]);
        FTPerFGAPercentage = stod(advStats["FT/FGA"]);

        oppPace = stod(advOppStats["Pace"]);
        oppORtg = stod(advOppStats["ORtg"]);
        oppFtr = stod(advOppStats["FTr"]);
        oppThreeAttemptRate = stod(advOppStats["3PAr"]);
        oppTrueShooting = stod(advOppStats["TS%"]);
        oppTotalReboundingPercentage = stod(advOppStats["TRB%"]);
        oppAssistPercentage = stod(advOppStats["AST%"]);
        oppStealPercentage = stod(advOppStats["STL%"]);
        oppBlockPercentage = stod(advOppStats["BLK%"]);
        oppEffectiveFG = stod(advOppStats["eFG%"]);
        oppTurnoverPercentage = stod(advOppStats["TOV%"]);
        oppORebPercentage = stod(advOppStats["ORB%"]);
        oppFTPerFGAPercentage = stod(advOppStats["FT/FGA"]);
    }
    
    string name;
    double games;
    double wins;
    double losses;
    double WLPercentage;
    double confWins;
    double confLosses;
    double confPercentage;
    double homeWins;
    double homeLosses;
    double homePercentage;
    double awayWins;
    double awayLosses;
    double awayPercentage;
    double SOS;
    double SRS;
    double pointsPerGame;
    double pointsAgainstPerGame;
    double FGPerGame;
    double FGAPerGame;
    double FGPercentage;
    double threesPerGame;
    double threesAPerGame;
    double threePercentage;
    double FTPerGame;
    double FTAPerGame;
    double FTPercentage;
    double offRebPerGame;
    double totRebPerGame;
    double assistPerGame;
    double stealsPerGame;
    double blocksPerGame;
    double turnoversPerGame;
    double personalFoulsPerGame;

    double oppPointsPerGame;
    double oppPointsAgainstPerGame;
    double oppFGPerGame;
    double oppFGAPerGame;
    double oppFGPercentage;
    double oppThreesPerGame;
    double oppThreesAPerGame;
    double oppThreePercentage;
    double oppFTPerGame;
    double oppFTAPerGame;
    double oppFTPercentage;
    double oppOffRebPerGame;
    double oppTotRebPerGame;
    double oppAssistPerGame;
    double oppStealsPerGame;
    double oppBlocksPerGame;
    double oppTurnoversPerGame;
    double oppPersonalFoulsPerGame;

    double pace;
    double ORtg;
    double Ftr;
    double ThreeAttemptRate;
    double trueShooting;
    double totalReboundingPercentage;
    double assistPercentage;
    double stealPercentage;
    double blockPercentage;
    double effectiveFG;
    double turnoverPercentage;
    double ORebPercentage;
    double FTPerFGAPercentage;

    double oppPace;
    double oppORtg;
    double oppFtr;
    double oppThreeAttemptRate;
    double oppTrueShooting;
    double oppTotalReboundingPercentage;
    double oppAssistPercentage;
    double oppStealPercentage;
    double oppBlockPercentage;
    double oppEffectiveFG;
    double oppTurnoverPercentage;
    double oppORebPercentage;
    double oppFTPerFGAPercentage;
};

#endif