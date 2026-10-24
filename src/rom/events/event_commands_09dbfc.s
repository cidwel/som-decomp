; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DBFC
.include "src/rom/event_command_macros.inc"
event_38D_command_DBFC:
    event_actor_walk 5, 3, 0
event_38D_command_DBFF:
    event_actor_walk 7, 2, 4
event_38D_command_DC02:
    event_wait_idle 
