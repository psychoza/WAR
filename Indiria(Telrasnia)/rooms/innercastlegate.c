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
  short_desc = gates_short;
  long_desc  = gates_long; // Needs a description
 dest_dir = ({
    roomdir + "inside", "gates",
    roomdir + "outworld", "out",
  });
  items = ({
    "ground", gates_ground, // Needs a description
    "floor", "=ground",
    "gates", gates_gates, // Needs a description
    "gate", "=gates",
    "portcullis", "=gates",
    "grass", gates_grass, // Needs a description
    "weeds", "=grass",
    "wall", gates_wall, // Needs a description
    "walls", "=wall",
  });
}