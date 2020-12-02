#include "programlama.h"
#include <QFile>
#include <QDebug>
#include <QIntValidator>
#include <iostream>
#include <QApplication>

programlama::programlama()
{

}

WordsList::WordsList()				// constructor
{
    header = new WordNode;				// create sentinels
    trailer = new WordNode;
    header->next = trailer;						// have them point to each other
    trailer->prev = header;
}

WordsList::~WordsList()				// destructor
{
    while (!empty()) removeBack();					// remove all but sentinels
    delete header;									// remove the sentinels
    delete trailer;
}

bool WordsList::empty() const				// is list empty?
{
    return (header->next == trailer);
}

void WordsList::addBack(const string &e)		// add to back of list
{
    //qDebug() << QString::fromStdString(e) <<endl;
    add(trailer, e);
}

void WordsList::add(WordNode* v, const string& e)	// insert new node before v
{

    WordNode* u = new WordNode;				// create a new node for e
    u->word = e;

    u->next = v;							// link u in between v
    u->prev = v->prev;						// ... and v->prev
    v->prev->next = u;							// correct code should be
    v->prev = u;							// like this
    //qDebug() << QString::fromStdString(u->word) <<endl;
    //v->prev->next	= v->prev	= u;				// WRONG CODE ! (Page : 127)
}

void WordsList::removeBack()					// remove from back
{
    // Liste boş mu?
    if (empty())
    {
        qDebug() << "List is empty !" << endl;
        return;
    }

    remove(trailer->prev);
}

void WordsList::remove(WordNode* v)
{													// remove node v
    WordNode* u = v->prev;						// predecessor
    WordNode* w = v->next;						// successor
    u->next = w;							// unlink v from list
    w->prev = u;
    delete v;
}

void WordsList::printH2T()
{
    if (empty())
    {
        qDebug() << "List is empty !" << endl;
        return;
    }

    WordNode* first = header->next;
    while (first != trailer)
    {
        cout << first->word << endl;
        first = first->next;
    }
}

int WordsList::lenList()
{
    int counter = 0;
    WordNode* first = header->next;
    while (first != trailer)
    {
        counter++;
        first = first->next;
    }
    return counter;
}

WordNode WordsList::getWordNode(int index){
    int counter = 0;
    WordNode* first = header->next;
    while (counter < index)
    {
        counter++;
        first = first->next;
    }

    return *first;
}


bool  programlama::empty()				// is list empty?
{
    return (list.header->next == list.trailer);
}

void programlama:: File2Struct()
{
    string inputWord;
    QString inputWord2;

    QFile mFile (":/dosya/sozluk.txt");
    if(!mFile.open(QFile ::ReadOnly | QFile::Text)){
        qDebug() << "dosya acilmadi..";
    }
    else
        qDebug() <<"dosya acildii";

    WordNode *current = list.header->next;
    QTextStream in(&mFile);
    while (!in.atEnd()){
        inputWord2 = in.readLine();
        inputWord = inputWord2.toStdString();
        list.addBack(inputWord);
    }
     mFile.close();

     qDebug() << list.lenList();
}

WordNode programlama::GetRandomWord()
{
    if (empty())
    {
        WordNode error;
        error.word = "-1";
        return error;
    }

    srand(time(NULL));
    return list.getWordNode(rand() % list.lenList());
}

WordNode programlama::EliminateWords(WordNode randomWord2, int isNormal)
{
    string saveCurrent, saveRandomWord = randomWord2.word;

        if ((randomWord2.word == "ara"
            || randomWord2.word == "ele"
            || randomWord2.word == "iki")
            && isNormal == 1)
        {
            if (randomWord2.score[1] = 1)
            {
                WordNode* current = list.header->next;
                while (current != list.trailer) {

                    for (int i = 0; current->word[i]; i++)
                    {
                        if (current->word[i] == randomWord2.word[0])
                        {
                            elenenler(randomWord2.word[0]);
                            current = current->prev;
                            list.remove(current->next);
                        }
                    }
                    current = current->next;
                }
            }
            else if (randomWord2.score[1] = 2)
            {
                WordNode* current = list.header->next;
                while (current != list.trailer) {

                    for (int i = 0; current->word[i]; i++)
                    {
                        if (current->word[i] == randomWord2.word[1])
                        {
                            elenenler(randomWord2.word[1]);
                            current = current->prev;
                            list.remove(current->next);
                        }
                    }
                    current = current->next;
                }
            }
            else if (randomWord2.score[1] >= 3)
            {
                WordNode* current = list.header->next;
                while (current != list.trailer) {

                    for (int i = 0; current->word[i]; i++)
                    {
                        if (current->word[i] == randomWord2.word[0] ||
                            current->word[i] == randomWord2.word[1])
                        {
                            current = current->next;
                        }
                    }
                    current = current->prev;
                    list.remove(current->next);
                }
            }
        }
            if (randomWord2.score[0] == 0 && randomWord2.score[1] == 0)
            {
                randomWord2.word = WordEditor(randomWord2.word);
                for (int i = 0; randomWord2.word[i]; i++)
                {
                    elenenler(randomWord2.word[i]);
                }
                WordNode* current = list.header->next;
                while (current != list.trailer)
                {
                    for (size_t i = 0; randomWord2.word[i]; i++)
                    {

                        if (randomWord2.word[i] == '*') continue;
                        for (size_t j = 0; current->word[j]; j++)
                        {
                            if (current->word[j] == randomWord2.word[i])
                            {
                                current = current->prev;
                                list.remove(current->next);
                                goto escape;
                            }
                        }
                    }
                escape:	current = current->next;
                }
            }
            else
            {
                WordNode* current = list.header->next;
                while (current != list.trailer)
                {
                    saveCurrent = current->word;
                    current->score[0] = current->score[1] = 0;
                    if (isNormal != 1)
                        WordEditor(current->word);
                    CalculateBlackScore(current, randomWord2);
                    CalculateWhiteScore(current, randomWord2);

                    randomWord2.word = saveRandomWord;
                    current->word = saveCurrent;

                    if (current->score[0] != randomWord2.score[0] || current->score[1] != randomWord2.score[1])
                    {
                        current = current->next;
                        list.remove(current->prev);
                    }
                    else
                        current = current->next;
                }
            }

            return GetRandomWord();
}

void programlama::CalculateWhiteScore(WordNode *down, WordNode up)
{
    if(up.word == down->word){
        down->score[1] = 0;
        return;
    }
    for (int i = 0; up.word[i]; i++)
        {
            for (int j = 0; down->word[j]; j++)
            {
                if (up.word[i] == down->word[j]) down->score[1]++;
            }
        }
}

void programlama::CalculateBlackScore(WordNode *down, WordNode up)
{
    if(up.word == down->word)
     {
        down->score[0] = 0 ;
        return;
    }

    for (int i = 0; up.word[i] && down->word[i]; i++)
        {
            if (up.word[i] == down->word[i])
            {
                //up.word[i] = down->word[i] = NULL;
                down->score[0]++;
            }
        }
}

void programlama::HumanToMachine()
{
    WordNode randomWord = GetRandomWord(); //TAKE RANDOM WORD

    //LETTER ELIMINATING PART
    while (true)
    {
        qDebug() << "Remainder Words Number : " << list.lenList() << endl;
        cout << "Guessed Word : " << randomWord.word << endl;
        qDebug() << "Score of Black: ";		cin >> randomWord.score[0];
        qDebug() << "Score of White: ";		cin >> randomWord.score[1];
        if (randomWord.score[0] == -1 || randomWord.score[1] == -1)	break;
        //else if (randomWord.score[0] )					//WHEN WORD WAS FOUND, PROGRAM WİLL HALT.
        //randomWord = EliminateWords(randomWord);
    }
}

void programlama:: DeletingFromLetters(char *letter)
{
    WordNode* current = list.header->next;
    while (current != list.trailer)
    {
        for (unsigned  int i = 0; current->word[i]; i++)
        {
            if (current->word[i] == *letter)
            {
                list.remove(current->prev);
                break;
            }
        }
        current = current->next;
    }
    return;
}

void programlama::AddWord2Dictionary(string word)
{
    string line = "\n";
    QFile mFile ("C:/Users/batu_/Desktop/Algoritmaqt/sozluk.txt");
    if(!mFile.open( QFile::Append| QFile::Text)){
        qDebug() << "dosya acilmadi..";
    }
    else
        qDebug() <<"dosya acildii";
    //mFile.write(word);
    mFile.write(QByteArray::fromStdString(word));
    mFile.write(QByteArray::fromStdString(line));
     mFile.close();
    return;
}

string programlama::WordEditor(string s)
{
    int again = 0;
    for (unsigned  int i = 0; s[i] != '\0'; i++)
    {
        for (unsigned  int j = 0; s[j] != '\0'; j++)
        {
            if (s[i] == s[j]) again++;
            if (again > 1)
            {
                s[j] = NULL;
                again = 1;
            }
        }
        again = 0;
    }
    return s;
}

void programlama::MachineToHuman()
{
    WordNode secretWord = GetRandomWord();
    WordNode inputWord;

    while (true)
    {
        qDebug() << "Estimated Word : ";
        cin >> inputWord.word;

        if (inputWord.word == secretWord.word)
        {
            qDebug() << endl << "--------Correct estimate-----" << endl;
            return;
        }
        else if(inputWord.word == "-1")
        {
            qDebug() << endl << "---Game Over---" << endl;
            return;
        }
        else
        {
            qDebug() << endl << "-------Wrong Estimate-------" << endl;
            inputWord.score[0] = inputWord.score[1] = 0;
            CalculateBlackScore(&inputWord, secretWord);
            CalculateWhiteScore(&inputWord, secretWord);
            qDebug() << "Black Score : " << inputWord.score[0] << endl;
            qDebug() << "White Score : " << inputWord.score[1] << endl << endl;
        }
    }
}
string programlama::elenenler(char harf = 0) {
    if (harf == 0)
        return this->alfabe;

    for (int i = 0; i < this->alfabe.length()-1; i++) {
        if (this->alfabe[i] == harf)
            this->alfabe[i] = NULL;
    }

    return this->alfabe;
}
