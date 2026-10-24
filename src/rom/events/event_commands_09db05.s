; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DB05
.include "src/rom/event_command_macros.inc"
event_38D_command_DB05:
    event_actor_walk 5, 1, 0
event_38D_command_DB08:
    event_wait_idle 
