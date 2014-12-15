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
  short_desc = southbirchstreet_3_short; // Needs a description
  long_desc  = southbirchstreet_3_long; // Needs a description
 dest_dir = ({
    roomdir + "southbirchstreet_2", "north",
    // Possible Shop Entrance
  });
  items = ({
    "ground", southbirchstreet_3_ground, // Needs a description
    "floor", "=ground",
    "buildings", southbirchstreet_3_buildings, // Needs a description
    "building", "=buildings",
    "houses", "=buildings",
    "house", "=buildings",
    "shops", "=buildings",
    "shop", "=buildings",
  });
}