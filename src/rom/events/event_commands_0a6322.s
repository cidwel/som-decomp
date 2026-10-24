; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6322
.include "src/rom/event_command_macros.inc"
event_555_command_6322:
    event_wait 32
