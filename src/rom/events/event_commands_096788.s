; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6788
.include "src/rom/event_command_macros.inc"
event_1B2_command_6788:
    event_wait 0
