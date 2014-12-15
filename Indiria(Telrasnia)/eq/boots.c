inherit "obj/armour";

id(string s) {
  if(s=="boots" || s=="leather boots" || s=="thick boots") {return 1;}
  return ::id(s);
}

reset(arg) {
  ::reset(arg);

  if(arg) return;
  set_name("boots");
  set_short("A worn pair of thick leather boots");
  set_long(
"These pair of boots are made of a thick leather to prevent possible burns\n"
"when working with hot metal and flames. They are covered in a layer of soot\n"
"and the leather is matted down in several places as a result of much use by\n"
"their previous owner.\n");

  set_ac(1);
  set_weight(1);
  set_value(300);
  set_type("feet");
}

query_creator() { return "Psychoza"; }