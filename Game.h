#ifndef GAME_H
#define GAME_H

#include <string>
#include <cassert>  //assert
#include <iostream> //ostream
#include <functional> //less
#include <algorithm>
#include "Team.h"

using namespace std;

class game {
public:
    game(team home_in, team away_in) : home(home_in),
        away(away_in) {
        homeScore = 0;
        awayScore = 0;
        totalScore = 0;
        SRS = home.SRS - away.SRS;
        if (SRS > 30) {
            strengthFactor = .5;
        }
        else if (SRS > 25) {
            strengthFactor = .6;
        }
        else if (SRS > 20) {
            strengthFactor = .7;
        }
        else if (SRS > 15) {
            strengthFactor = .8;
        }
        else if (SRS > 10) {
            strengthFactor = .9;
        }
        else if (SRS > 5) {
            strengthFactor = .95;
        }
        else if (SRS > 0) {
            strengthFactor = 1;
        }
        else if (SRS > -5) {
            strengthFactor = 1 / .95;
        }
        else if (SRS > -10) {
            strengthFactor = 1 / .9;
        }
        else if (SRS > -15) {
            strengthFactor = 1 / .8;
        }
        else if (SRS > -20) {
            strengthFactor = 1 / .7;
        }
        else if (SRS > -25) {
            strengthFactor = 1 / .6;
        }
        else {
            strengthFactor = 1 / .5;
        }
    }

    void setConferences() {
        if (home.name == "Stony Brook",
            "Hartford",
            "Albany",
            "Massachusetts-Lowell",
            "Vermont",
            "New Hampshire",
            "Binghamton",
            "UMBC") {
            homeConference = "America East";
        }
        else if (home.name == "Wichita State",
            "Cincinnati",
            "Memphis",
            "SMU",
            "Houston",
            "Tulsa",
            "East Carolina",
            "Tulane",
            "Connecticut",
            "Temple",
            "South Florida",
            "Central Florida") {
            homeConference = "American";
        }
        else if (home.name == "Duquesne",
            "Dayton",
            "St. Bonaventure",
            "Saint Louis",
            "Richmond",
            "Viriginia Commonwealth",
            "Rhode Island",
            "George Mason",
            "Davidson",
            "Massachusetts",
            "La Salle",
            "Fordham",
            "George Washington",
            "Saint Joseph's") {
            homeConference = "Atlantic 10";
        }
        else if (home.name == "Duke",
            "Florida State",
            "Louisville",
            "Virginia Tech",
            "Virginia",
            "Boston College",
            "Georgia Tech",
            "North Carolina State",
            "Pittsburgh",
            "Miami",
            "Syracuse",
            "Clemson",
            "Notre Dame",
            "Wake Forest",
            "North Carolina") {
            homeConference = "ACC";
        }
        else if (home.name == "Liberty",
            "North Florida",
            "North Alabama",
            "Lipscomb",
            "Florida Gulf Coast",
            "Jacksonville",
            "Stetson",
            "NJIT",
            "Kennesaw State") {
            homeConference = "Atlantic Sun";
        }
        else if (home.name == "Baylor",
            "Texas Christian",
            "West Virginia",
            "Kansas",
            "Oklahoma",
            "Texas",
            "Texas Tech",
            "Iowa State",
            "Oklahoma State",
            "Kansas State") {
            homeConference = "Big 12";
        }
        else if (home.name == "Seton Hall",
            "Butler",
            "Villanova",
            "Providence",
            "Creighton",
            "Xavier",
            "St.John's (NY)",
            "Marquette",
            "Georgetown",
            "DePaul") {
            homeConference = "Big East";
        }
        else if (home.name == "Montana",
        "Northern Colorado",
        "Southern Utah",
        "Sacramento State",
        "Idaho State",
        "Montana State",
        "Eastern Washington",
        "Portland State",
        "Idaho",
        "Northern Arizona",
        "Weber State") {
        homeConference = "Big Sky";
        }
        else if (home.name == "Winthrop",
        "Radford",
        "Presbyterian",
        "Hampton",
        "South Carolina Upstate",
        "North Carolina-Asheville",
        "Campbell",
        "Charleston Southern",
        "Longwood",
        "Gardner-Webb",
        "High Point") {
        homeConference = "Big South";
        }
        else if (home.name == "Michigan State",
        "Illinois",
        "Maryland",
        "Indiana",
        "Rutgers",
        "Wisconsin",
        "Purdue",
        "Minnesota",
        "Penn State",
        "Iowa",
        "Michigan",
        "Ohio State",
        "Nebraska",
        "Northwestern") {
        homeConference = "Big Ten";
        }
        else if (home.name == "UC-Riverside",
        "UC-Irvine",
        "UC-Santa Barbara",
        "Hawaii",
        "Cal State Northridge",
        "Long Beach State",
        "Cal Poly",
        "UC-Davis",
        "Cal State Fullerton") {
        homeConference = "Big West";
        }
        else if (home.name == "William & Mary",
            "Charleston",
            "Hofstra",
            "Drexel",
            "Northeastern",
            "Towson",
            "Delaware",
            "Elon",
            "James Madison",
            "North Carolina-Wilmington") {
            homeConference = "Colonial";
        }
        else if (home.name == "Charlotte",
        "Louisiana Tech",
        "Florida Atlantic",
        "Western Kentucky",
        "North Texas",
        "Old Dominion",
        "Florida International",
        "Alabama-Birmingham",
        "Marshall",
        "Texas-San Antonio",
        "Texas-El Paso",
        "Rice",
        "Middle Tennessee",
        "Southern Miss") {
        homeConference = "Conference USA";
        }
        else if (home.name == "Wright State",
        "Youngstown State",
        "Northern Kentucky",
        "Milwaukee",
        "Cleveland State",
        "Green Bay",
        "Oakland",
        "Illinois-Chicago",
        "Detroit Mercy",
        "IUPUI") {
        homeConference = "Horizon";
        }
        else if (home.name == "Princeton",
        "Yale",
        "Harvard",
        "Brown",
        "Dartmouth",
        "Columbia",
        "Cornell",
        "Pennsylvania") {
        homeConference = "Ivy";
        }
        else if (home.name == "Quinnipiac",
        "Manhattan",
        "Rider",
        "Siena",
        "Monmouth",
        "Fairfield",
        "Saint Peter's",
        "Niagara",
        "Iona",
        "Canisius",
        "Marist") {
        homeConference = "MAAC";
        }
        else if (home.name == "Akron",
        "Kent State",
        "Bowling Green",
        "Buffalo",
        "Ohio",
        "Miami (OH)",
        "Ball State",
        "Central Michigan",
        "Northern Illinois",
        "Toledo",
        "Western Michigan",
        "Eastern Michigan") {
        homeConference = "MAC";
        }
        else if (home.name == "Norfolk State",
        "North Carolina A&T",
        "Bethune-Cookman",
        "South Carolina State",
        "North Carolina Central",
        "Morgan State",
        "Florida A&M",
        "Delaware State",
        "Maryland-Eastern Shore",
        "Coppin State",
        "Howard") {
        homeConference = "MEAC";
        }
        else if (home.name == "Northern Iowa",
        "Bradley",
        "Loyola Chicago",
        "Drake",
        "Indiana State",
        "Valparaiso",
        "Missouri State",
        "Southern Illinois",
        "Illinois State",
        "Evansville") {
        homeConference = "MISSOURI";
        }
    }

    void setScores() {
        homeScore = (home.pointsPerGame +
            away.pointsAgainstPerGame) / 2;
        awayScore = (away.pointsPerGame +
            home.pointsAgainstPerGame) / 2;
    }

    void homeAdvantage() {
        if (home.homePercentage < .2) {
            return;
        }
        else if (away.awayPercentage == 1) {
            return;
        }
        else if (home.homePercentage < .4 &&
            away.awayPercentage > .8) {
            return;
        }

        else if (home.homePercentage < .5 &&
            away.awayPercentage > .8) {
            homeScore += 1;
        }
        else if (home.homePercentage < .7 &&
            away.awayPercentage > .8) {
            homeScore += 2;
        }
        else if (home.homePercentage < .5 &&
            away.awayPercentage > .5) {
            homeScore += 2;
            awayScore -= 1;
        }
        else if (home.homePercentage < .7 &&
            away.awayPercentage > .5) {
            homeScore += 3;
            awayScore -= 2;
        }
        else {
            homeScore += 4;
            awayScore -= 3;
        }
    }

    int homeThreePointPercentage() {
        if (home.threePercentage > .4 &&
            away.oppThreePercentage < .28) {
            return 3;
        }
        else if (home.threePercentage > .4 &&
            away.oppThreePercentage < .32) {
            return 4;
        }
        else if (home.threePercentage > .4 &&
            away.oppThreePercentage < .38) {
            return 5;
        }
        else if (home.threePercentage > .4 &&
            away.oppThreePercentage < .4) {
            return 6;
        }
        else if (home.threePercentage > .4) {
            return 7;
        }
        else if (home.threePercentage > .38 && 
            away.oppThreePercentage < .28) {
            return 1;
        }
        else if (home.threePercentage > .38 &&
            away.oppThreePercentage < .32) {
            return 2;
        }
        else if (home.threePercentage > .38 &&
            away.oppThreePercentage < .36) {
            return 3;
        }
        else if (home.threePercentage > .38 &&
            away.oppThreePercentage < .38) {
            return 4;
        }
        else if (home.threePercentage > .38) {
            return 5;
        }
        else if (home.threePercentage > .36 &&
            away.oppThreePercentage < .32) {
            return 1;
        }
        else if (home.threePercentage > .38 &&
            away.oppThreePercentage < .36) {
            return 2;
        }
        else if (home.threePercentage > .38 &&
            away.oppThreePercentage < .38) {
            return 3;
        }
        else if (home.threePercentage > .38) {
            return 4;
        }
        else if (home.threePercentage > .36 &&
            away.oppThreePercentage < .32) {
            return 1;
        }
        else if (home.threePercentage > .36 &&
            away.oppThreePercentage < .36) {
            return 2;
        }
        else if (home.threePercentage > .36 &&
            away.oppThreePercentage < .38) {
            return 3;
        }
        else if (home.threePercentage > .36) {
            homeScore += 4;
            return 4;
        }
        else if (home.threePercentage > .34 &&
            away.oppThreePercentage < .36) {
            return 1;
        }
        else if (home.threePercentage > .34 &&
            away.oppThreePercentage < .38) {
            return 2;
        }
        else if (home.threePercentage > .36) {
            return 3;
        }
        else if (home.threePercentage > .32 &&
            away.oppThreePercentage < .38 &&
            away.oppThreePercentage > .34) {
            return 1;
        }
        else if (home.threePercentage > .32 &&
            away.oppThreePercentage > .38) {
            return 2;
        }
        return 0;
    }

    void homeThreeRate() {
        int num = homeThreePointPercentage();
        if (home.ThreeAttemptRate > .46) {
            homeScore += num * 2;
        }
        else if (home.ThreeAttemptRate > .44) {
            homeScore += num * 1.75;
        }
        else if (home.ThreeAttemptRate > .42) {
            homeScore += num * 1.5;
        }
        else if (home.ThreeAttemptRate > .4) {
            homeScore += num * 1.25;
        }
        else {
            homeScore += num;
        }
    }

    void awayThreeRate() {
        int num = awayThreePointPercentage();
        if (away.ThreeAttemptRate > .46) {
            awayScore += num * 2;
        }
        else if (away.ThreeAttemptRate > .44) {
            awayScore += num * 1.75;
        }
        else if (away.ThreeAttemptRate > .42) {
            awayScore += num * 1.5;
        }
        else if (away.ThreeAttemptRate > .4) {
            awayScore += num * 1.25;
        }
        else {
            awayScore += num;
        }
    }

    /*void homeFGPercentage() {
        if (home.FGPercentage > .48 &&
            away.oppFGPercentage < .32) {
            homeScore += 3;
        }
        else if (home.FGPercentage > .48 &&
            away.oppThreePercentage < .36) {
            homeScore += 4;
        }
        else if (home.FGPercentage > .48 &&
            away.oppFGPercentage < .38) {
            homeScore += 5;
        }
        else if (home.FGPercentage > .48 &&
            away.oppFGPercentage < .4) {
            homeScore += 6;
        }
        else if (home.FGPercentage > .48) {
            homeScore += 7;
        }
        else if (home.FGPercentage > .46 &&
            away.oppFGPercentage < .32) {
            homeScore += 1;
        }
        else if (home.FGPercentage > .46 &&
            away.oppFGPercentage < .34) {
            homeScore += 2;
        }
        else if (home.FGPercentage > .46 &&
            away.oppFGPercentage < .36) {
            homeScore += 3;
        }
        else if (home.FGPercentage > .46 &&
            away.oppFGPercentage < .38) {
            homeScore += 4;
        }
        else if (home.FGPercentage > .46) {
            homeScore += 5;
        }
        else if (home.FGPercentage > .44 &&
            away.oppFGPercentage < .36) {
            homeScore += 1;
        }
        else if (home.FGPercentage > .44 &&
            away.oppFGPercentage < .38) {
            homeScore += 2;
        }
        else if (home.FGPercentage > .44 &&
            away.oppFGPercentage < .4) {
            homeScore += 3;
        }
        else if (home.FGPercentage > .44) {
            homeScore += 4;
        }
        else if (home.FGPercentage > .42 &&
            away.oppFGPercentage < .38 &&
            away.oppFGPercentage > .34) {
            homeScore += 1;
        }
        else if (home.FGPercentage > .42 &&
            away.oppFGPercentage < .4) {
            homeScore += 2;
        }
        else if (home.FGPercentage > .42 &&
            away.oppFGPercentage < .42) {
            homeScore += 3;
        }
        else if (home.FGPercentage > .42) {
            homeScore += 4;
        }
        else if (home.FGPercentage > .4 &&
            away.oppFGPercentage < .4 &&
            away.oppFGPercentage > .36) {
            homeScore += 1;
        }
        else if (home.FGPercentage > .4 &&
            away.oppFGPercentage < .42) {
            homeScore += 2;
        }
        else if (home.FGPercentage > .4) {
            homeScore += 3;
        }
        else if (home.FGPercentage > .38 &&
            away.oppFGPercentage < .42 &&
            away.oppFGPercentage > .39) {
            homeScore += 1;
        }
        else if (home.FGPercentage > .38 &&
            away.oppFGPercentage > .42) {
            homeScore += 2;
        }
    }*/

    void homeEffectiveFGPercentage() {
        if (home.effectiveFG > .55 &&
            away.oppEffectiveFG < .42) {
            homeScore += 3;
        }
        else if (home.effectiveFG > .55 &&
            away.oppEffectiveFG < .44) {
            homeScore += 4;
        }
        else if (home.effectiveFG > .55 &&
            away.oppEffectiveFG < .46) {
            homeScore += 5;
        }
        else if (home.effectiveFG > .55 &&
            away.oppEffectiveFG < .48) {
            homeScore += 6;
        }
        else if (home.effectiveFG > .55) {
            homeScore += 7;
        }
        else if (home.effectiveFG > .53 &&
            away.oppEffectiveFG < .42) {
            homeScore += 2;
        }
        else if (home.effectiveFG > .53 &&
            away.oppEffectiveFG < .44) {
            homeScore += 3;
        }
        else if (home.effectiveFG > .53 &&
            away.oppEffectiveFG < .46) {
            homeScore += 4;
        }
        else if (home.effectiveFG > .53 &&
            away.oppEffectiveFG < .48) {
            homeScore += 5;
        }
        else if (home.effectiveFG > .53) {
            homeScore += 6;
        }
        else if (home.effectiveFG > .51 &&
            away.oppEffectiveFG < .46) {
            homeScore += 2;
        }
        else if (home.effectiveFG > .51 &&
            away.oppEffectiveFG < .48) {
            homeScore += 3;
        }
        else if (home.effectiveFG > .51 &&
            away.oppEffectiveFG < .50) {
            homeScore += 4;
        }
        else if (home.effectiveFG > .51) {
            homeScore += 5;
        }
        else if (home.effectiveFG > .49 &&
            away.oppEffectiveFG < .46 &&
            away.oppEffectiveFG > .42) {
            homeScore += 1;
        }
        else if (home.effectiveFG > .49 &&
            away.oppEffectiveFG < .48) {
            homeScore += 2;
        }
        else if (home.effectiveFG > .49 &&
            away.oppEffectiveFG < .5) {
            homeScore += 3;
        }
        else if (home.effectiveFG > .49 &&
            away.oppEffectiveFG > .5) {
            homeScore += 4;
        }
        else if (home.effectiveFG > .47 &&
            away.oppEffectiveFG < .48 &&
            away.oppEffectiveFG > .52) {
            homeScore += 1;
        }
        else if (home.effectiveFG > .47 &&
            away.oppEffectiveFG < .5) {
            homeScore += 2;
        }
        else if (home.effectiveFG > .47 &&
            away.oppEffectiveFG > .5) {
            homeScore += 3;
        }
        else if (home.effectiveFG > .45 &&
            away.oppEffectiveFG < .50 &&
            away.oppEffectiveFG > .54) {
            homeScore += 1;
        }
        else if (home.effectiveFG > .45 &&
            away.oppEffectiveFG > .54) {
            homeScore += 2;
        }
    }

    void awayEffectiveFGPercentage() {
        if (away.effectiveFG > .55 &&
            home.oppEffectiveFG < .42) {
            awayScore += 3;
        }
        else if (away.effectiveFG > .55 &&
            home.oppEffectiveFG < .44) {
            awayScore += 4;
        }
        else if (away.effectiveFG > .55 &&
            home.oppEffectiveFG < .46) {
            awayScore += 5;
        }
        else if (away.effectiveFG > .55 &&
            home.oppEffectiveFG < .48) {
            awayScore += 6;
        }
        else if (away.effectiveFG > .55) {
            awayScore += 7;
        }
        else if (away.effectiveFG > .53 &&
            home.oppEffectiveFG < .42) {
            awayScore += 2;
        }
        else if (away.effectiveFG > .53 &&
            home.oppEffectiveFG < .44) {
            awayScore += 3;
        }
        else if (away.effectiveFG > .53 &&
            home.oppEffectiveFG < .46) {
            awayScore += 4;
        }
        else if (away.effectiveFG > .53 &&
            home.oppEffectiveFG < .48) {
            awayScore += 5;
        }
        else if (away.effectiveFG > .53) {
            awayScore += 6;
        }
        else if (away.effectiveFG > .51 &&
            home.oppEffectiveFG < .46) {
            awayScore += 2;
        }
        else if (away.effectiveFG > .51 &&
            home.oppEffectiveFG < .48) {
            awayScore += 3;
        }
        else if (away.effectiveFG > .51 &&
            home.oppEffectiveFG < .50) {
            awayScore += 4;
        }
        else if (away.effectiveFG > .51) {
            awayScore += 5;
        }
        else if (away.effectiveFG > .49 &&
            home.oppEffectiveFG < .46 &&
            home.oppEffectiveFG > .42) {
            awayScore += 1;
        }
        else if (away.effectiveFG > .49 &&
            home.oppEffectiveFG < .48) {
            awayScore += 2;
        }
        else if (away.effectiveFG > .49 &&
            home.oppEffectiveFG < .5) {
            awayScore += 3;
        }
        else if (away.effectiveFG > .49 &&
            home.oppEffectiveFG > .5) {
            awayScore += 4;
        }
        else if (away.effectiveFG > .47 &&
            home.oppEffectiveFG < .48 &&
            home.oppEffectiveFG > .52) {
            awayScore += 1;
        }
        else if (away.effectiveFG > .47 &&
            home.oppEffectiveFG < .5) {
            awayScore += 2;
        }
        else if (away.effectiveFG > .47 &&
            home.oppEffectiveFG > .5) {
            awayScore += 3;
        }
        else if (away.effectiveFG > .45 &&
            home.oppEffectiveFG < .50 &&
            home.oppEffectiveFG > .54) {
            awayScore += 1;
        }
        else if (away.effectiveFG > .45 &&
            home.oppEffectiveFG > .54) {
            awayScore += 2;
        }
    }

    int awayThreePointPercentage() {
        if (away.threePercentage > .4 &&
            home.oppThreePercentage < .28) {
            return 3;
        }
        else if (away.threePercentage > .4 &&
            home.oppThreePercentage < .32) {
            return 4;
        }
        else if (away.threePercentage > .4 &&
            home.oppThreePercentage < .38) {
            return 5;
        }
        else if (away.threePercentage > .4 &&
            home.oppThreePercentage < .4) {
            return 6;
        }
        else if (away.threePercentage > .4) {
            return 7;
        }
        else if (away.threePercentage > .38 &&
            home.oppThreePercentage < .28) {
            return 1;
        }
        else if (away.threePercentage > .38 &&
            home.oppThreePercentage < .32) {
            return 2;
        }
        else if (away.threePercentage > .38 &&
            home.oppThreePercentage < .36) {
            return 3;
        }
        else if (away.threePercentage > .38 &&
            home.oppThreePercentage < .38) {
            return 4;
        }
        else if (away.threePercentage > .38) {
            return 5;
        }
        else if (away.threePercentage > .36 &&
            home.oppThreePercentage < .32) {
            return 1;
        }
        else if (away.threePercentage > .36 &&
            home.oppThreePercentage < .36) {
            return 2;
        }
        else if (away.threePercentage > .36 &&
            home.oppThreePercentage < .38) {
            return 3;
        }
        else if (away.threePercentage > .36) {
            return 4;
        }
        else if (away.threePercentage > .34 &&
            home.oppThreePercentage < .36) {
            return 1;
        }
        else if (away.threePercentage > .34 &&
            home.oppThreePercentage < .38) {
            return 2;
        }
        else if (away.threePercentage > .36) {
            return 3;
        }
        else if (away.threePercentage > .32 &&
            home.oppThreePercentage < .38 &&
            home.oppThreePercentage > .34) {
            return 1;
        }
        else if (away.threePercentage > .32 &&
            home.oppThreePercentage > .38) {
            return 2;
        }
        return 0;
    }



    /*void awayFGPercentage() {
        if (away.FGPercentage > .48 &&
            home.oppFGPercentage < .32) {
            awayScore += 3;
        }
        else if (away.FGPercentage > .48 &&
            home.oppThreePercentage < .36) {
            awayScore += 4;
        }
        else if (away.FGPercentage > .48 &&
            home.oppFGPercentage < .38) {
            awayScore += 5;
        }
        else if (away.FGPercentage > .48 &&
            home.oppFGPercentage < .4) {
            awayScore += 6;
        }
        else if (away.FGPercentage > .48) {
            awayScore += 7;
        }
        else if (away.FGPercentage > .46 &&
            home.oppFGPercentage < .32) {
            awayScore += 1;
        }
        else if (away.FGPercentage > .46 &&
            home.oppFGPercentage < .34) {
            awayScore += 2;
        }
        else if (away.FGPercentage > .46 &&
            home.oppFGPercentage < .36) {
            awayScore += 3;
        }
        else if (away.FGPercentage > .46 &&
            home.oppFGPercentage < .38) {
            awayScore += 4;
        }
        else if (away.FGPercentage > .46) {
            awayScore += 5;
        }
        else if (away.FGPercentage > .44 &&
            home.oppFGPercentage < .36) {
            awayScore += 1;
        }
        else if (away.FGPercentage > .44 &&
            home.oppFGPercentage < .38) {
            awayScore += 2;
        }
        else if (away.FGPercentage > .44 &&
            home.oppFGPercentage < .4) {
            awayScore += 3;
        }
        else if (away.FGPercentage > .44) {
            awayScore += 4;
        }
        else if (away.FGPercentage > .42 &&
            home.oppFGPercentage < .38 &&
            home.oppFGPercentage > .34) {
            awayScore += 1;
        }
        else if (away.FGPercentage > .42 &&
            home.oppFGPercentage < .4) {
            awayScore += 2;
        }
        else if (away.FGPercentage > .42 &&
            home.oppFGPercentage < .42) {
            awayScore += 3;
        }
        else if (away.FGPercentage > .42) {
            awayScore += 4;
        }
        else if (away.FGPercentage > .4 &&
            home.oppFGPercentage < .4 &&
            home.oppFGPercentage > .36) {
            awayScore += 1;
        }
        else if (away.FGPercentage > .4 &&
            home.oppFGPercentage < .42) {
            awayScore += 2;
        }
        else if (away.FGPercentage > .4) {
            awayScore += 3;
        }
        else if (away.FGPercentage > .38 &&
            home.oppFGPercentage < .42 &&
            home.oppFGPercentage > .39) {
            awayScore += 1;
        }
        else if (away.FGPercentage > .38 &&
            home.oppFGPercentage > .42) {
            awayScore += 2;
        }
    }*/

    void homeTurnoverPercentage() {
        if (home.turnoverPercentage > .2 &&
            away.oppTurnoverPercentage > .23) {
            homeScore -= 7;
        }
        else if (home.turnoverPercentage > .2 &&
            away.oppTurnoverPercentage > .2) {
            homeScore -= 5;
        }
        else if (home.turnoverPercentage > .2 &&
            away.oppTurnoverPercentage > .18) {
            homeScore -= 4;
        }
        else if (home.turnoverPercentage > .2 &&
            away.oppTurnoverPercentage > .16) {
            homeScore -= 3;
        }
        else if (home.turnoverPercentage > .2 &&
            away.oppTurnoverPercentage > .14) {
            homeScore -= 1;
        }
        else if (home.turnoverPercentage > .18 &&
            away.oppTurnoverPercentage > .23) {
            homeScore -= 5;
        }
        else if (home.turnoverPercentage > .18 &&
            away.oppTurnoverPercentage > .2) {
            homeScore -= 4;
        }
        else if (home.turnoverPercentage > .18 &&
            away.oppTurnoverPercentage > .18) {
            homeScore -= 3;
        }
        else if (home.turnoverPercentage > .18 &&
            away.oppTurnoverPercentage > .17) {
            homeScore -= 2;
        }
        else if (home.turnoverPercentage > .16 &&
            away.oppTurnoverPercentage > .2) {
            homeScore -= 2;
        }
        else if (home.turnoverPercentage > .16 &&
            away.oppTurnoverPercentage > .18) {
            homeScore -= 1;
        }
    }

    void awayTurnoverPercentage() {
        if (away.turnoverPercentage > .2 &&
            home.oppTurnoverPercentage > .23) {
            awayScore -= 7;
        }
        else if (away.turnoverPercentage > .2 &&
            home.oppTurnoverPercentage > .2) {
            awayScore -= 5;
        }
        else if (away.turnoverPercentage > .2 &&
            home.oppTurnoverPercentage > .18) {
            awayScore -= 4;
        }
        else if (away.turnoverPercentage > .2 &&
            home.oppTurnoverPercentage > .16) {
            awayScore -= 3;
        }
        else if (away.turnoverPercentage > .2 &&
        home.oppTurnoverPercentage > .14) {
        awayScore -= 1;
        }
        else if (away.turnoverPercentage > .18 &&
        home.oppTurnoverPercentage > .23) {
        awayScore -= 5;
        }
        else if (away.turnoverPercentage > .18 &&
        home.oppTurnoverPercentage > .2) {
        awayScore -= 4;
        }
        else if (away.turnoverPercentage > .18 &&
        home.oppTurnoverPercentage > .18) {
        awayScore -= 3;
        }
        else if (away.turnoverPercentage > .18 &&
        home.oppTurnoverPercentage > .17) {
        awayScore -= 2;
        }
        else if (away.turnoverPercentage > .16 &&
        home.oppTurnoverPercentage > .2) {
        awayScore -= 2;
        }
        else if (away.turnoverPercentage > .16 &&
        home.oppTurnoverPercentage > .18) {
        awayScore -= 1;
        }
    }

    void upsetFactor() {
        if (SRS > 15) {
            if (away.threesAPerGame > .48) {
                strengthFactor += .1;
            }
            else if (away.threesAPerGame > .44) {
                strengthFactor += .085;
            }
            else if (away.threesAPerGame > .40) {
                strengthFactor += .07;
            }
            if (away.effectiveFG > .55) {
                strengthFactor += .09;
            }
            else if (away.effectiveFG > .525) {
                strengthFactor += .06;
            }
            if (away.oppTurnoverPercentage > .23) {
                strengthFactor += .15;
            }
            else if (away.oppTurnoverPercentage > .2) {
                strengthFactor += .11;
            }
            else if (away.oppTurnoverPercentage > .18) {
                strengthFactor += .06;
            }
        }
        if (SRS < -15) {
            if (home.threesAPerGame > .48) {
                strengthFactor -= .1;
            }
            else if (home.threesAPerGame > .44) {
                strengthFactor -= .085;
            }
            else if (home.threesAPerGame > .40) {
                strengthFactor -= .07;
            }
            if (home.effectiveFG > .55) {
                strengthFactor -= .09;
            }
            else if (home.effectiveFG > .525) {
                strengthFactor -= .06;
            }
            if (home.oppTurnoverPercentage > .23) {
                strengthFactor -= .15;
            }
            else if (home.oppTurnoverPercentage > .2) {
                strengthFactor -= .11;
            }
            else if (home.oppTurnoverPercentage > .18) {
                strengthFactor -= .06;
            }
        }
    }

    void homeOffensiveRebounding() {
        if (home.ORebPercentage > .35 &&
            away.oppORebPercentage > .325) {
            homeScore += 3;
        }
        else if (home.ORebPercentage > .35 &&
            away.oppORebPercentage > .31) {
            homeScore += 2;
        }
        else if (home.ORebPercentage > .35 &&
            away.oppORebPercentage > 29) {
            homeScore += 1;
        }
        else if (home.ORebPercentage > .32 &&
            away.oppORebPercentage > .325) {
            homeScore += 2;
        }
        else if (home.ORebPercentage > .32 &&
            away.oppORebPercentage > .31) {
            homeScore += 1;
        }
        else if (home.ORebPercentage > .3 &&
            away.oppORebPercentage > .325) {
            homeScore += 1;
        }
    }

    void awayOffensiveRebounding() {
        if (away.ORebPercentage > .35 &&
            home.oppORebPercentage > .325) {
            awayScore += 3;
        }
        else if (away.ORebPercentage > .35 &&
            home.oppORebPercentage > .31) {
            awayScore += 2;
        }
        else if (away.ORebPercentage > .35 &&
            home.oppORebPercentage > 29) {
            awayScore += 1;
        }
        else if (away.ORebPercentage > .32 &&
            home.oppORebPercentage > .325) {
            awayScore += 2;
        }
        else if (away.ORebPercentage > .32 &&
            home.oppORebPercentage > .31) {
            awayScore += 1;
        }
        else if (away.ORebPercentage > .3 &&
            home.oppORebPercentage > .325) {
            awayScore += 1;
        }
    }

    void strength() {
        if (strengthFactor > 1) {
            homeScore = homeScore / strengthFactor;
        }
        else {
            awayScore = awayScore * strengthFactor;
        }
    }

    pair<string, int> runGame() {
        setScores();
        homeAdvantage();
        //homeFGPercentage();
        //awayFGPercentage();
        homeEffectiveFGPercentage();
        awayEffectiveFGPercentage();
        homeThreePointPercentage();
        awayThreePointPercentage();
        homeTurnoverPercentage();
        awayTurnoverPercentage();
        homeOffensiveRebounding();
        awayOffensiveRebounding();
        upsetFactor();
        strength();
        pair<string, int> result;
        if (homeScore > awayScore) {
            result = { home.name, homeScore - awayScore };
        }
        else if (awayScore > homeScore) {
            result = { away.name, awayScore - homeScore };
        }
        else {
            result = { "tie", 0 };
        }
        return result;
    }


private:
    team home;
    team away;
    string homeConference;
    string awayConference;
    double SRS;
    double homeScore;
    double awayScore;
    double totalScore;
    double strengthFactor;
};

#endif