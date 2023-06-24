#ifndef __JUG_H__
#define __JUG_H__
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <functional>
#include <climits>
using namespace std;


enum GraphActions { fillA, fillB, emptyA, emptyB, pourAB, pourBA };
static std::map<std::string, GraphActions> mapActions;

class JugState {
    public: 
        int a;          // whats is jugA
        int b;          // whats in jugB
        string action;
        int cost;
        // few comparing operators
        bool operator>(const JugState& rhs) const {
            return cost > rhs.cost;
        }

        bool operator<(const JugState& rhs) const {
            return cost < rhs.cost;
        }

        JugState& operator=(const JugState& rhs) {
            if (this != &rhs) {
                a = rhs.a ;
                b = rhs.b ;
                action = rhs.action ;
                cost = rhs.cost ;
            }
            return *this;
        }
};

class Jug {
       public:
        Jug(int,int,int,int,int,int,int,int,int);
        ~Jug();
        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &solution);
    private:
        int capA, capB, goal, costFillA, costFillB, costEmptyA, costEmptyB, costPourAB, costPourBA ;
        void nextAction(priority_queue<JugState, vector<JugState>, greater<JugState>> &pq, 
            vector <vector <int>> &distance, int currentA, int currentB, string action, int cost, JugState previousState, vector <vector<JugState>> &predecessor);
        //anything else you need 
};


#endif
