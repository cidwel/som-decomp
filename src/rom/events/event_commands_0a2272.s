; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2272
.include "src/rom/event_command_macros.inc"
event_4B6_command_2272:
    event_actor_walk 0, 1, 24
event_4B6_command_2275:
    event_wait_idle 
event_4B6_command_2276:
    event_call 1148
event_4B6_command_2278:
    event_call 2008
