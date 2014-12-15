#define BARRENS "/wizards/psychoza/war/telrasnia/telrasnia_city_env" // This creates a reference to the city environment.
inherit BARRENS // This causes this to room to inherit some of its properties from that environment.
#define OUTSIDE "/room/"  // 
#define roomdir "wizards/psychoza/war/telrasnia//rooms/" // This creates a variable to the rooms folder so you don't have to type out the path many times.
#define mondir "wizards/psychoza/war/telrasnia//mon/" // This creates a variable to the monsters folder so you don't have to type out the path many times.
#define objdir "wizards/psychoza/war/telrasnia//obj/" // This creates a variable to the objects folder so you don't have to type out the path many times.
#define curPlayer this_player()
#define curObject this_object()
#define curPlayerName curPlayer->query_name()
#include "../descs.h" // this pulls in all of the variables created in the descriptions header file to use for the room.

void reset(status arg){
  if (arg) return;
  ::reset();
  property = ({ "outdoors" }); // Sets the room as "outdoors" so you can la sky etc.
  short_desc = gate_short; // Sets the rooms short description (the one used in "brief" mode)
  long_desc  = gate_long; // Sets the rooms long description (the one used in "verbose" mode) // Needs a description
 dest_dir = ({
    roomdir + "dukeboulevard_1", "gates", // Adds to the room's "destination directories" the "gates" exit which moves the player to "dukeboulevard_1"
    roomdir + "outworld", "out", // Adds to the room's "destination directories" the "out" exit which moves the player to "outworld"
  });
  items = ({
    "ground", gate_ground, //Adds an item "ground" to the room's "items" so a player can la "ground" // Needs a description
    "floor", "=ground", // If a player does "la floor" it will result in the same as "la ground"
    "gates", gate_gates, // Needs a description
    "gate", "=gates",
    "portcullis", "=gates",
    "grass", gate_grass, // Needs a description
    "weeds", "=grass",
    "wall", gate_wall, // Needs a description
    "walls", "=wall",
  });
}