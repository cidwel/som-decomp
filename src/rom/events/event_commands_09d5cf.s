; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D5CF
.include "src/rom/event_command_macros.inc"
event_36F_command_D5CF:
    event_actor_walk 6, 2, 0
event_36F_command_D5D2:
    event_actor_walk 7, 3, 0
event_36F_command_D5D5:
    event_wait_idle 
