#define CITY "/wizards/psychoza/war/telrasnia/telrasnia_city_env"
inherit CITY
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
  short_desc = outsidetemple_short;
  long_desc = outsidetemple_long;
  dest_dir = ({    
    roomdir + "centralsquare", "north",
    roomdir + "generalstore", "east",
    roomdir + "temple", "south",
  });
  items = ({
    "ground", outsidetemple_ground,
    "floor", "=ground",
  });
}