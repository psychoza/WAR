inherit "/obj/treasure";

id(string str) {
  return (str=="forge" || str=="wooden counter" || str=="wood counter" );
}

string query_name(){ return "forge"; }

void reset(status arg) {
  if(arg) return;
  
  set_short("A large wooden counter");
  set_long(
"A large wooden counter is placed here to divide the room in two. The\n"+
"customer side, and the workers side. The surface of the counter is marred\n"+
"by small slit marks, as if the counter would have been a working top earlier.\n"+
"Some pieces of leather can be seen almost everywhere on the surface of the\n"+
"counter. A large note has been fastened nails onto the front of the counter.\n");
  set_weight(100);
  set_value(500);
}

get() {
  printf("What would you do with an extremely heavy counter in your pocket? Is that even possible? NO!\n");
  return 0;
}

query_creator() { return "Grungemen"; }
