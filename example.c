#include "src/loggr.h" // or just <loggr.h> if installed

int main() {
  // enables colors!
  SetColors(1);
  // enables labels!
  SetLabels(1);
  Debug("Colour and labeling has been set.");
  Log("Level: debug.");
  SetLogLevel(DEBUG);
  Debug("Enemy at index: %i", 3);
  Log("Hello!");
  Warning("Your computer sucks.");
  SetLogLevel(LOG);
  Log("Level: error.");
  SetLogLevel(ERROR);
  Warning("You have something on your shirt.");
  Error("Your computer has virus!");
  return 0;
}