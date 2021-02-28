#define MAX_NAME_LENGTH 50

typedef struct {
    int HP;
    int MATK;
    int MRES;
    char ELE;
    char name[MAX_NAME_LENGTH];
}Character;

void showCharacterInfo(Character* character);
