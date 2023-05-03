#ifndef PLAYLIST_H
#define PLAYLIST_H
class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string uniqueID, string songName, string artistName, int songLength, PlaylistNode* nextNodePtr = nullptr );
        void InsertAfter(PlaylistNode* nodeLoc);
        void SetNext(PlaylistNode* nodeptr);
        string GetID(); 
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode() const;

    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    
};

#endif