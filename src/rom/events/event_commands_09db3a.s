; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DB3A
.include "src/rom/event_command_macros.inc"
event_38D_command_DB3A:
    event_actor_walk 5, 3, 0
event_38D_command_DB3D:
    event_wait_idle 
