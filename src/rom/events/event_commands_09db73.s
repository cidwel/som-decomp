; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DB73
.include "src/rom/event_command_macros.inc"
event_38D_command_DB73:
    event_actor_walk 0, 2, 2
event_38D_command_DB76:
    event_wait_idle 
