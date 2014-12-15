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
  x_coord = 5;
  y_coord = 3;
  property = ({ "outdoors"});
  short_desc = "The open barrens";
  long_desc  = barrens_2_desc;
 dest_dir = ({
    roomdir + "barrens1", "north",
    roomdir + "barrens4", "northeast",
    roomdir + "barrens5", "east",
    roomdir + "barrens6", "southeast",
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