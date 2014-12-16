#define BARRENS "/wizards/psychoza/war/telrasnia/telrasnia_env"
inherit BARRENS
#define OUTSIDE "/room/"
#define roomdir "wizards/psychoza/war/telrasnia//rooms/"
#define mondir "wizards/psychoza/war/telrasnia//mon/"
#define objdir "wizards/psychoza/war/telrasnia//obj/"
#define curPlayer this_player()
#define curObject this_object()
#define curPlayerName curPlayer->query_name()
#include "../descs.h"

void reset(status arg){
  if (arg) return;
  ::reset();
  property = ({ "outdoors" });
  short_desc = insidegates_short;
  long_desc  = insidegates_long;
 dest_dir = ({
    roomdir + "armoury", "north",
    roomdir + "weaponry", "south",
    roomdir + "centralsquare", "west",
    roomdir + "gates", "out",
  });
  items = ({
    "ground", insidegates_ground,
    "floor", "=ground",
  });
}