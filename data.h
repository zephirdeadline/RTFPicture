//Super fichier .h de la B de D :P

typedef struct CharacterInfo CharacterInfo;

CharacterInfo* AddInfoStart(CharacterInfo *c, char *name);
void ConfigFile(char oprion);
CharacterInfo* AddInfo(CharacterInfo *c, char *name);
void ModifInfo(CharacterInfo *c, char *name, char *newName);
CharacterInfo* RemoveInfo(CharacterInfo *c, char *name);
CharacterInfo* ArrayData();
char* Concat(char *a, char *b);
int CountList(CharacterInfo *c);
int CounterData();
void ShowList(CharacterInfo *c);
CharacterInfo* ArrayRec(int size);
struct CharacterInfo
{
	char *name;
	char *image;
	char *caracter;	
	CharacterInfo *next;
};


