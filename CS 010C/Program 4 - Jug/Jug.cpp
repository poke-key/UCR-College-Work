#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "Jug.h"
using namespace std;


Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA) :
    capA(Ca), capB(Cb), goal(N), costFillA(cfA), 
    costFillB(cfB), costEmptyA(ceA), costEmptyB(ceB), 
    costPourAB(cpAB), costPourBA(cpBA)
{
    // to handle case statement, much cleaner
    mapActions["fill A"] = fillA;
    mapActions["fill B"] = fillB;
    mapActions["empty A"] = emptyA;
    mapActions["empty B"] = emptyB;
    mapActions["pour A B"] = pourAB;
    mapActions["pour B A"] = pourBA;
}
Jug::~Jug(){

}

int Jug::solve(string &solution){
    solution = "" ;
    // check validity of data, if not we cannot operate the jugs
    if(goal > capB || capA <= 0 || capB <= 0 || capA > capB 
        || costFillA < 0 || costFillB < 0 || costEmptyA < 0 || costEmptyB < 0 
            || costPourAB < 0 || costPourBA < 0 || capB > 1000) {
        return -1;
    }

    vector <vector <JugState> > predecessor(capA + 1, vector <JugState>(capB + 1));
    vector <vector <int> > distance(capA + 1, vector <int>(capB + 1, INT_MAX));
    priority_queue<JugState, vector<JugState>, greater<JugState>> PQ;

    // start with vertex 0
    PQ.push({0, 0, "", 0});
    distance[0][0] = 0;
  
    while(!PQ.empty()){
        int howmany = PQ.size();
        for(int i = 0; i < howmany; i++){
            JugState currentState = PQ.top();
            PQ.pop();
            JugState tempState = currentState ;

            // did we reach the  desired goal yet?
            if( (tempState.a == 0 && tempState.b == goal) || (tempState.b == 0 && tempState.a == goal)) {
                vector <string> path;
                while (currentState.action != "") {
                    path.push_back(currentState.action);
                    currentState = predecessor[currentState.a][currentState.b];
                }
                reverse(path.begin(), path.end());
                for(string str : path){
                    str += "\n" ;           // add newline
                    solution += str;        // append to solution
                }
                solution += "success " + to_string(tempState.cost); // append total cost
                // return success 
                return true;
            }
            // perform all other fill and empty actions to reach desired goal
            nextAction(PQ, distance, tempState.a, tempState.b, "fill A", costFillA, currentState, predecessor);
            nextAction(PQ, distance, tempState.a, tempState.b, "fill B", costFillB, currentState, predecessor);
            nextAction(PQ, distance, tempState.a, tempState.b, "empty A", costEmptyA, currentState, predecessor);
            nextAction(PQ, distance, tempState.a, tempState.b, "empty B", costEmptyB, currentState, predecessor);
            nextAction(PQ, distance, tempState.a, tempState.b, "pour A B", costPourAB, currentState, predecessor);
            nextAction(PQ, distance, tempState.a, tempState.b, "pour B A", costPourBA, currentState, predecessor);
        }
    }
    // exhausted, no success
    solution = "";
    return false;
}

void Jug::nextAction(priority_queue<JugState, vector<JugState>, greater<JugState>> &PQ, 
            vector <vector <int>> &distance, int cjugA, int cjugB, string action, int cost, JugState previousJugState, vector <vector<JugState>> &predecessor){
    int jugA, jugB;
    // take action as needed
    switch (mapActions[action]) {
    case fillA :
        jugA = capA;
        jugB = cjugB;
        break ;
    case fillB:
        jugB = capB;
        jugA = cjugA;
        break ;
    case emptyA:
        jugA = 0;
        jugB = cjugB;
        break ;
    case emptyB:
        jugB = 0;
        jugA = cjugA;
        break ;
    case pourAB:
        {
            int neededByB = capB - cjugB;
            if(cjugA >= neededByB){
                jugA = cjugA - neededByB;
                jugB = capB;
            }
            else{
                jugA = 0;
                jugB = cjugB + cjugA;
            }
        }
        break ;
    case pourBA:
        {
            int neededByA = capA - cjugA;
            if(cjugB >= neededByA){
                jugB = cjugB - neededByA;
                jugA = capA;
            }
            else{
                jugB = 0;
                jugA = cjugA + cjugB;
            }
        }
    default:
        break ;
    }

    if(distance[jugA][jugB] > distance[cjugA][cjugB] + cost){
        PQ.push({jugA, jugB, action, previousJugState.cost + cost});
        predecessor[jugA][jugB] = previousJugState;
        distance[jugA][jugB] = distance[cjugA][cjugB] + cost;
    }   
}
