; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D812
.include "src/rom/event_command_macros.inc"
event_378_command_D812:
    event_actor_effect_0f 
