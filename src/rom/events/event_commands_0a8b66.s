; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B66
.include "src/rom/event_command_macros.inc"
event_66D_command_8B66:
    event_wait_idle 
event_66D_command_8B67:
    event_wait 0
