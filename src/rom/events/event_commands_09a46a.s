; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A46A
.include "src/rom/event_command_macros.inc"
event_267_command_A46A:
    event_wait 0
