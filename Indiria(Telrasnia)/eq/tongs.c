inherit "obj/weapon";

id(string s) {
  if(s=="tongs" || s=="steel tongs") {
	return 1; 
  }
  return ::id(s);
}

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_short("A pair of steel tongs");
  set_long(
"A pair of steel tongs with longer than normal arms meant to hold objects\n"
"firmly at a distance. The tongs end in the shape of an 'L' adding to its\n"
"ability to hold something in between them. There appears to be what used\n"
"to be ridges but from a long time of use have been worn down.\n");
  set_name("steel tongs");
  set_class(15);
  set_value(350);
  set_weight(2);
  set_wield2h(0);
  set_weapon_type("ancient");
}

query_creator() { return "Psychoza"; }