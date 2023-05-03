#include <iostream>
using namespace std;
#include "Playlist.h"

PlaylistNode::PlaylistNode() {  //default constructor
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}
PlaylistNode::PlaylistNode(string uniqueID , string songName , string artistName , int songLength , PlaylistNode* nextNodePtr) { //parameterized constructor
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    this->nextNodePtr = nextNodePtr;
}
void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
   PlaylistNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}
void PlaylistNode::SetNext(PlaylistNode* nodeptr) {     //Mutator
    nextNodePtr = nodeptr;
}
string PlaylistNode::GetID() {         //Accessor
    return uniqueID;
}
string PlaylistNode::GetSongName() {   //Accessor
    return songName;
}
string PlaylistNode::GetArtistName() {  //Accessor
    return artistName;
}
int PlaylistNode::GetSongLength() {     //Accessor
    return songLength;
}
PlaylistNode* PlaylistNode::GetNext() { 
    return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() const {

    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}
