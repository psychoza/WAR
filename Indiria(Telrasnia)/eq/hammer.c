inherit "obj/weapon";

id(string s) {
  if(s=="hammer" || s=="heavy hammer" || s=="steel hammer") {
	return 1; 
  }
  return ::id(s);
}

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_short("A heavy hammer made of steel");
  set_long(
"A small hammer meant to be held in only one hand and easily manueverable as\n"
"it is commonly used for the shaping of metal. Small chips and dents are on\n"
"the steel head from being broken in by its previous owner. The handle is\n"
"made of a solid wood with worn out leather wrappings along its length to\n"
"give it a better grip.\n");
  set_name("steel hammer");
  set_class(20);
  set_value(850);
  set_weight(4);
  set_wield2h(0);
  set_weapon_type("bludgeon");
}

query_creator() { return "Psychoza"; }