; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $144B
.include "src/rom/event_command_macros.inc"
event_084_command_144B:
    event_actor_walk 4, 0, 0
event_084_command_144E:
    event_wait_idle 
