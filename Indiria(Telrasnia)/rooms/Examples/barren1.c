#define BARRENS "/wizards/psychoza/the_bad_lands/barrens/barrens_env"
inherit BARRENS
#define OUTSIDE "/room/"
#define roomdir "wizards/psychoza/the_bad_lands/barrens/rooms/"
#define mondir "wizards/psychoza/the_bad_lands/barrens/mon/"
#define objdir "wizards/psychoza/the_bad_lands/barrens/obj/"
#define curPlayer this_player()
#define curObject this_object()
#define curPlayerName curPlayer->query_name()
#include "../descs.h"

void reset(status arg){
  if (arg) return;
  ::reset();
  property = ({ "outdoors" });
  short_desc = "The open barrens";
  long_desc  = barrens_1_desc;
 dest_dir = ({
    roomdir + "barrens2", "south",
    roomdir + "barrens3", "northeast",
	roomdir + "barrens4", "east",
	roomdir + "barrens5", "southeast",	
  });
  items = ({
    "ground", barrens_ground,
    "floor", "=ground",
    "rocks", barrens_rocks,
    "stones", "=rocks",
    "grass", barrens_grass,
    "weeds", "=grass",
  });
}