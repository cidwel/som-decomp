; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BD06
.include "src/rom/event_command_macros.inc"
event_2C2_command_BD06:
    event_actor_walk 4, 0, 0
event_2C2_command_BD09:
    event_wait_idle 
event_2C2_command_BD0A:
    event_wait 128
event_2C2_command_BD0C:
    event_change_map 633
event_2C2_command_BD0E:
    event_call 1928
