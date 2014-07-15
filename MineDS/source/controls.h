#include <nds.h>

KEYPAD_BITS getControlKey(int);
void setControlKey(int, KEYPAD_BITS);
void saveControlData(FILE* data);
void loadControlData(FILE* data);
void setHerobrineOn(bool on);
bool getHerobrineOn();
void setDrawMode(bool on);
bool getDrawMode();