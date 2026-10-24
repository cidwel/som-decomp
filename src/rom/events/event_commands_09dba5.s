; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DBA5
.include "src/rom/event_command_macros.inc"
event_38D_command_DBA5:
    event_actor_walk 7, 3, 4
event_38D_command_DBA8:
    event_wait_idle 
