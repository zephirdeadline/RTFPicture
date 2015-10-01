//Super fichier .h de la B de D :P


void ConfigFile(char oprion);
void AddInfo(char *name, char *image, char *caracter);
void ModifInfo();
void RemoveInfo();

typedef struct CharacterInfo CharacterInfo;
struct CharacterInfo
{
	char *name;
	char *image;
	char *caracter;	
};

CharacterInfo* ArrayInfo();
