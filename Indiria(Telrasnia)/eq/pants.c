inherit "obj/armour";

id(string s) {
  if(s=="pants" || s=="loose pants") {return 1;}
  return ::id(s);
}

reset(arg) {
  ::reset(arg);

  if(arg) return;
  set_name("loose pants");
  set_short("A pair of loose pants");
  set_long(

"A pair of pants that appear they would fit loosely in the legs. They are\n"
"made of a thick denim material to keep from catching fire easily. They\n"
"have a pocket on the front of each thigh to allow the wearer a place to\n"
"rest their hands or put small mundane things in. The edges of the material\n"
"have begun to unweave due to excessive use. They appear to be very\n"
"comfortable.");

  set_ac(2);
  set_weight(1);
  set_value(300);
  set_type("legs");
}

query_creator() { return "Psychoza"; }