#include "clickTest.h"

int main () {
   ClickTest g(1600,900,"Clicker Test");
   g.run();
   ClickTest lvlone(1600,900, "First Floor");
   lvlone.run();

   return 0;
}