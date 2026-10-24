; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $30F0
.include "src/rom/event_command_macros.inc"
event_4E1_command_30F0:
    event_wait 0
