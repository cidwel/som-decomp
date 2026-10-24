; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2AAC
.include "src/rom/event_command_macros.inc"
event_106_command_2AAC:
    event_actor_walk 5, 2, 0
event_106_command_2AAF:
    event_actor_walk 6, 2, 0
event_106_command_2AB2:
    event_wait_idle 
event_106_command_2AB3:
    event_wait 8
