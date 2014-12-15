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
  short_desc = dukeboulevard_1_short; // Needs a description
  long_desc  = dukeboulevard_1_long; // Needs a description
 dest_dir = ({    
    roomdir + "northbirchstreet_1", "north",
    roomdir + "southbirchstreet_1", "south",
    roomdir + "dukeboulevard_2", "west",
    roomdir + "gate", "gates",
  });
  items = ({
    "ground", dukeboulevard_1_ground, // Needs a description
    "floor", "=ground",
    "buildings", dukeboulevard_1_buildings, // Needs a description
    "building", "=buildings",
    "houses", "=buildings",
    "house", "=buildings",
    "shops", "=buildings",
    "shop", "=buildings",
  });
}