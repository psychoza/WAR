inherit "obj/armour";

id(string s) {
  if(s=="apron" || s=="leather apron") return 1;
}

reset(arg) {
  ::reset(arg);

  if(arg) return;
  set_name("apron");
  set_short("A worn leather apron");
  set_long(
"A wide piece of thick leather with a thick loop on top to go around one's\n"+
"neck. There is a long strap on each side with which the apron could be\n"+
"fastened by tying them behind one's back. The apron has a three large\n"+
"pockets in the front, and by the looks of it, judging from a discolored\n"+
"patch there used to be a fourth one once. All around, the soft leather\n"+
"is scarred and covered by dirty splotches.\n");

  set_ac(4);
  set_weight(3);
  set_value(200);
  set_type("torso");
}

query_creator() { return "Monte"; }
