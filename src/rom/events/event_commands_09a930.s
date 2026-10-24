; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A930
.include "src/rom/event_command_macros.inc"
event_289_command_A930:
    event_wait 0
