; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $401F
.include "src/rom/event_command_macros.inc"
event_4E6_command_401F:
    event_wait 0
