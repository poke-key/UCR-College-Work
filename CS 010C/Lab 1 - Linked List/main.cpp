#include <iostream>
using namespace std;
#include "Playlist.h"

int length(PlaylistNode* headPtr) {
    int count = 0;
    PlaylistNode* currNode = headPtr;
    
    while(currNode != nullptr) {
        count++;
        currNode = currNode -> GetNext();
    }
    return count;
}

void PrintMenu(string title) {
    PlaylistNode* headPtr = nullptr;
    PlaylistNode* tailPtr = nullptr;
    char input_char = '\0';
    string dummy;

    while(input_char != 'q') {
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option:" << endl;
        cin >> input_char;
        getline(cin, dummy); // clear the additional newline left by cin    
        switch(input_char) {
            case 'a' : 
            {
                string uniqueID, songName, artistName;
                int songLength;
                cout << "ADD SONG" << endl;
                cout << "Enter song's unique ID:" << endl;
                getline(cin, uniqueID);                     //getline() used to get full input and not stop at space
                cout << "Enter song's name:" << endl;
                getline(cin, songName);
                cout << "Enter artist's name:" << endl;
                getline(cin, artistName);
                cout << "Enter song's length (in seconds):" << endl;
                cout << endl;
                cin >> songLength;
                if( headPtr == nullptr ) //checks if list is empty
                {
                    headPtr = new PlaylistNode(uniqueID, songName, artistName, songLength); // creates new memory for a new song 
                    tailPtr = headPtr;        
                }
                else
                {
                    PlaylistNode* song = new PlaylistNode(uniqueID, songName, artistName, songLength);
                    tailPtr->InsertAfter(song);
                    tailPtr = song ;                // list is not empty and tail points to the last song
                }
                
                break;
            }
            case 'd' :
            {
                string uniqueID;
                cout << "REMOVE SONG" << endl;
                cout << "Enter song's unique ID:" << endl;
                cin >> uniqueID;
                
                PlaylistNode* currNode = headPtr;
                PlaylistNode* prevNode = nullptr;

                while(currNode != nullptr && currNode->GetID() != uniqueID) { //iterates through list, checks each node for the correct ID
                    prevNode = currNode;
                    currNode = currNode->GetNext();
                }
                if(currNode != nullptr) {
                    if(prevNode == nullptr)
                        headPtr = currNode->GetNext();
                    else
                        prevNode -> SetNext(currNode->GetNext());
                    
                    if(tailPtr == currNode) 
                        tailPtr = prevNode;
                    
                    cout << "\"" << currNode->GetSongName() << "\" removed." << endl;
                    cout << endl;
                    delete currNode;
                    // removes the currNode
                }
                break; 
                
            }
            case 'c' :
            {
                int curr_position;
                int new_position;
                cout << "CHANGE POSITION OF SONG" << endl;
                cout << "Enter song's current position:" << endl;
                cin >> curr_position;
                cout << "Enter new position for song:" << endl;
                cin >> new_position;
                int list_length = length(headPtr);
                if(new_position < 1)    //checks if input is less than 1 and moves song to number 1 spot
                    new_position = 1;
                if(new_position > list_length)
                    new_position = list_length;
                PlaylistNode* curr = headPtr;
                PlaylistNode* prev = nullptr;
                for(int i = 1; i < curr_position && curr != nullptr; i++) {
                    prev = curr;
                    curr = curr->GetNext();
                }
                if(curr == nullptr) {
                    break;
                }
                if(prev == nullptr) 
                   headPtr = curr->GetNext();
                else
                     prev->SetNext(curr->GetNext());
                if(tailPtr == curr)
                    tailPtr = prev;
                
                prev = nullptr;
                PlaylistNode* new_node = headPtr;
                for(int i = 1; i < new_position && new_node != nullptr; i++) {
                    prev = new_node;
                    new_node = new_node->GetNext();
                }
                if(prev == nullptr) 
                    headPtr = curr;
                else 
                    prev->SetNext(curr);
                curr->SetNext(new_node);
                cout << "\"" << curr->GetSongName() << "\" moved to position " << new_position << endl;
                cout << endl;
                break;
            }
            case 's' :
            {
                string artistName;
                cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
                cout << "Enter artist's name:" << endl;
                cout << endl;
                getline(cin, artistName);
                PlaylistNode* currNode = headPtr;
                int count = 1;
                while (currNode != nullptr) {   //iterates through list and checks if input name matches with artist name of all the songs
                    if(artistName == currNode->GetArtistName()) {
                        cout << count << "." << endl;
                        currNode->PrintPlaylistNode();
                        cout << endl;
                    }
                    currNode = currNode->GetNext();
                    count++;
                }
                break;
            }

            case 't' :
            {
                PlaylistNode* currNode = headPtr;
                int total_time = 0;
                while (currNode != nullptr) {   //calculates total time of playlist
                    total_time += currNode->GetSongLength(); //adds total time to song length for each iteration
                    currNode = currNode->GetNext();
                }
                cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
                cout << "Total time: " << total_time << " seconds" << endl;
                cout << endl ;
                break;
            }
            case 'o' :
            {
                
                PlaylistNode* currNode = headPtr;
                int count = 1;
                cout << title << " - OUTPUT FULL PLAYLIST" << endl;
                if(headPtr == nullptr) {    //checks if playlist is empty so it doesnt show any songs in playlist.
                    cout << "Playlist is empty" << endl;
                    cout << endl;
                }
                while (currNode != nullptr) { //displays all of the songs in playlist
                    cout << count << "." << endl; 
                    currNode->PrintPlaylistNode();
                    cout << endl;
                    currNode = currNode->GetNext();
                    count++;
                }
                break;
            }
        }
    }
}

int main() {
    string title;
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, title);
    PrintMenu(title);
}