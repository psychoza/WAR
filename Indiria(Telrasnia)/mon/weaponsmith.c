inherit "wizards/zeith/mob/talk_mob";
#define KILL_COUNTER_D "/wizards/mvx/raven/city/count_kills.c"

object apron,pants,hammer,tongs,gloves,boots;

id(string s) {
  if(s=="human" || s=="weaponsmith" || s=="human weaponsmith" || s=="man" ||
     s=="smith" || s=="bargough" || s=="Bargough" || s=="Weaponsmith") return 1;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  gloves = clone_object("/wizards/mvx/raven/weaponry/eq/gloves.c");
  move_object(gloves,this_object());
  boots = clone_object("/wizards/mvx/raven/weaponry/eq/boots.c");
  move_object(boots,this_object());
  apron = clone_object("/wizards/mvx/raven/weaponry/eq/apron.c");
  move_object(apron,this_object());
  pants = clone_object("/wizards/mvx/raven/weaponry/eq/pants.c");
  move_object(pants,this_object());
  hammer = clone_object("/wizards/mvx/raven/weaponry/eq/hammer.c");
  move_object(hammer,this_object());
  tongs = clone_object("/wizards/mvx/raven/weaponry/eq/tongs.c");
  move_object(tongs,this_object());
  command("wear all");
  command("wield hammer");
  command("lwield tongs");
  set_name("weaponsmith");
  set_short("Bargough, the master Weaponsmith of Ravenkall");
  set_race("human");
  set_long(
    "He is stocky middle aged man probably in his thirties. His dull gray eyes\n"
    "seem to match the ash effect that age has placed into his head of what used\n"
    "to be painted black. His face is roughed up with bristles only a few days\n"
    "old matching the same style as the hair on his head. He has a dark skin\n"
    "complexion that makes his eyes and hair stand out even more. He has a light\n"
    "hearted atmosphere about him and his face holds an ever present smirk.\n"
  );
  set_level(55);
  set_al(175);
  spells = ([]);
  add_skill("brawl",100, 50);
  add_skill("dirty blow",100);
  add_skill("throw sand",100);
  add_skill("weapon skill 1h bludgeon",200);
  add_skill("weapon skill 1h ancient",200);
  add_skill("leftwield",200);
  add_skill("inner strength",80);
  add_skill("critical",50);
  set_gender(1);
  set_no_turbo(1);
  add_str_bonus(135);
  add_dex_bonus(50);
  add_con_bonus(110);
  set_cha(85);

  load_chat(5, ({
    "Bargough states 'Making weapons is not easy but certainly is a good stress\n"
	"reliever.'\n",
    "The weaponsmith ponders aloud about adding a fuller to his weapon design style.\n",
    "Bargough mutters something quietly to himself.\n",
    "Bargough picks up a sword and runs his hand down the length of the blade.\n",
    "Bargough says 'I've got quite the queue keeping up with all these guards.'\n",
	"Bargough returns to his anvil and forge and continues his current project for a\n"
	"short while.\n",
    "",
  }));
  
  load_a_chat(5, ({
  	"Bargough swings his hammer menacingly.\n",
  	"Bargough growls 'You have made a grave mistake.'\n",	
  }));
}

heart_beat() {
  ::heart_beat();
  if(!useing && !casting) {
    if(!attacker_ob) busy = 0;
    else if(!present_clone(attacker_ob,environment(this_object()))) busy = 0;
  }
}

second_life() {
  ::second_life();
  KILL_COUNTER_D->add_kill();
}

faith_color(){
  return "green";
}

query_creator() { 
  return "Psychoza"; 
}