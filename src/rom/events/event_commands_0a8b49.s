; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B49
.include "src/rom/event_command_macros.inc"
event_66D_command_8B49:
    event_wait_idle 
