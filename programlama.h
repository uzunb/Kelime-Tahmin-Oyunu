#ifndef PROGRAMLAMA_H
#define PROGRAMLAMA_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

using namespace std;

struct WordNode
{
    string word;											// WordNodeent name
    int score[2];
    WordNode* next;										// next item in the list
    WordNode* prev;										// previous item in the list
};

struct WordsList
{
    WordNode* header;										// pointer to the header of list
    WordNode* trailer;									// pointer to the trailer of list

    WordsList();										// empty list constructor
    ~WordsList();									// destructor

    bool empty() const;										// is list empty?
    void addBack(const string& e);			// add to back of list
    void removeBack();										// remove from back
    void printH2T();
    int lenList();
    WordNode getWordNode(int index);

    void add(WordNode* v, const string& e);	// insert new node before v
    void remove(WordNode* v);								// remove node v
};


class programlama
{
public:
    programlama();
    WordsList list;
    void File2Struct();				//Transfer to list from dictionary.
    void HumanToMachine();
    void MachineToHuman();
    WordNode GetRandomWord();		//Generate random word.
    WordNode EliminateWords(WordNode randomWord2, int isNormal); //part of elimination words from the dictionary.
    void CalculateBlackScore(WordNode *currentWord, WordNode randomWord3);
    void CalculateWhiteScore(WordNode *currentWord, WordNode randomWord3);
    bool empty();
    void AddWord2Dictionary(string word);
    string WordEditor(string s);
    void DeletingFromLetters(char *letter);
    string elenenler(char harf);
    string alfabe = " a b c ç d e f g ğ h ı i j k l m n o ö p r s ş t u ü v y z ";
};


#endif // PROGRAMLAMA_H
