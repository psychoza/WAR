inherit "wizards/leper/room/shop";
#include "descs.h"
#define TP this_player()
#define TO this_object()

object weaponsmith;

void reset(int arg) {
  if(weaponsmith = "/wizards/mvx/raven/cloner_d"->clone_mob("wizards/mvx/raven/weaponry/mon/weaponsmith")) {
    move_object(weaponsmith, TO);
  }

  if(arg) return;

  set_light(1);
  short_desc = weaponry_short;
  long_desc = weaponry_long;
  max_profit = 2000;
  allow_selling = 1;
  dest_dir = ({
    "/wizards/mvx/raven/city/rooms/stellar4","west",
  });

  property = ({
    "indoors",
	"no_field",
  });
  items=({
    "wall", weaponry_walls ,
    "walls", "=wall",
    "floor", weaponry_floor,
	"ground", "=floor",
    "ceiling", weaponry_ceiling,
	"counter", weaponry_counter,
  });  
}

int wanted(object ob) {
  if(ob->is_weapon())
  return 1;
}

init() {
  ::init();
  add_action("read", "read");
  add_action("cmd_look", "look");
  add_action("cmd_smell", "smell");
  add_action("cmd_smell", "sniff");
  add_action("cmd_listen","listen");
  add_action("touch", "touch");
  add_action("touch", "feel");
  
  if(allow_selling) {
    if(is_mortal(TP) || is_arch(TP)) add_action("sell", "sell");
    add_action("value", "value");
  }
  add_action("list", "list");
  if(is_mortal(TP) || is_arch(TP)) add_action("buy", "buy");
}

sell(string str) {
  if(present("Bargough", TO)) {
    return ::sell(str);
  }
  else {
    write("The shopkeeper is not here.\n");
    return 1;
  }
  return 0;
}

buy(string str) {
  if(present("Bargough", TO)) {
    return ::buy(str);
  }
  else {
    write("The shopkeeper is not here.\n");
    return 1;
  }
  return 0;
}

list(string str) {
  if(present("Bargough", TO)) {
    return ::list(str);
  }
  else {
    write("The shopkeeper is not here.\n");
    return 1;
  }
  return 0;
}

read(str) {
  if(str=="plaque" || str=="sign" || str=="poster" || str=="list") {
    do_sign();
    return 1;
  }
  if(!str && str=="plaque" && !str=="sign" && !str=="poster" && !str=="list") {
    write("Read what?\n");
    return 1;
  }
}

cmd_look(str){
  if(str=="plaque" || str=="sign" || str=="at plaque" || str=="at sign" ||
    str=="poster" || str=="list" || str=="at poster" || str=="at list") {
    do_sign();
    return 1;
  }
  return 0;
}

cmd_smell(string arg) {
  write("You sniff the warm air smelling the burning scent of coal and heated metal.\n");
  TP->hit_player(1+random(2),"physical");
  return 1;
}

cmd_listen(string arg) {
  write("You listen carefully, but nothing except but the sounds of the burning\n"
  "forge are heard.\n");
  return 1;
}

touch(str) {
  if(str=="forge") {
    write("For some unknown reason you touch the searing hot forge and BURN your hand.\n");
    TP->hit_player(60+random(100),"fire");
	return 1;
  }
  if(str=="anvil") {
    write("You touch the anvil feeling the dents beat into the surface from years of use.\n");
	return 1;
  }
  if(!str=="forge" && !str=="anvil") {
    write("Touch what?\n");
	return 1;
  }
}

do_sign() {
  write("\n"+
        "  +---------------------------------+\n"+
        "  |  Welcome to The Silver Scabard  |\n"+
        "  |                                 |\n"+
        "  | 'Your local resource of quality |\n"+
		"  |            weapons.'            |\n"+
        "  |                                 |\n"+
        "  |                       -Bargough |\n"+
		"  +---------------------------------+\n");		
  return;
}

query_creator() { 
  return "Psychoza"; 
}
