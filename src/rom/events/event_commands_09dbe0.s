; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DBE0
.include "src/rom/event_command_macros.inc"
event_38D_command_DBE0:
    event_actor_walk 5, 1, 0
event_38D_command_DBE3:
    event_wait_idle 
