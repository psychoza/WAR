#define ROOM "/wizards/psychoza/the_bad_lands/barrens/barrens_env"
inherit ROOM;
#define OUTSIDE "/room/"
#include "../descs.h"

#define roomdir "wizards/psychoza/the_bad_lands/barrens/rooms/"
#define mondir "wizards/psychoza/the_bad_lands/barrens/mon/"
#define objdir "wizards/psychoza/the_bad_lands/barrens/obj/"
#define TPQN   this_player()->query_name()
#define TP this_player()
#define TO this_object()

void reset(status arg){
  if (arg) return;
  ::reset();
  x_coord = 6;
  y_coord = 2;
  property = ({ "outdoors"});
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