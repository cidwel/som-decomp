; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4ED0
.include "src/rom/event_command_macros.inc"
event_16D_command_4ED0:
    event_actor_walk 3, 0, 16
event_16D_command_4ED3:
    event_wait_idle 
