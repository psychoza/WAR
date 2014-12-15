inherit "lib/door";
inherit "room/room";
inherit "room/room/emotes";

#define curPlayer this_player()
#define curObject this_object()
#define curPlayerName curPlayer->query_name()
#define curTime "wizards/superfro/daemons/time_d"
#include "descs.h"

reset() {
  set_light(1);
  
  set_emotes(1, ({
	"A carriage barrels through the street causing passerbys to flee.\n",
	"Smoke wafts through on the back of a short gust from a nearby hearth.\n",
  }));
}

init() {
  ::init();
  add_action("do_dg", "dg");
  add_action("do_smell", "smell");
  add_action("do_listen", "listen");
}

do_listen(str) {
  if(!str) {
	if(curTime->query_time_of_day() == "day") {
      write(barrens_ground_listen_day);
    }
    if(curTime->query_time_of_day() == "night") {
      write(barrens_ground_listen_night);
    }    
    return 1; 
  }
  return 0;  
}

do_smell(str) {
  if(!str) {
	if(curTime->query_time_of_day() == "day") {
      write(barrens_ground_sound_day);
    }
    if(curTime->query_time_of_day() == "night") {
      write(barrens_ground_sound_night);
    }    
    return 1;
  }
  return 0;
}

do_dg(str) {
  if(query_property("no_dig")) {
    write("The ground here isn't soft enough to dig.\n");
    return 1;
  }
  return 0;
}
  
int is_virtual_room() { 
        if( previous_object() && program_name(previous_object()) == "cmds/player/map.c" ) return 1;
        return 0; 
}

query_creator() { return "Psychoza"; }
