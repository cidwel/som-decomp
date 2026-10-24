; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $64E3
.include "src/rom/event_command_macros.inc"
event_555_command_64E3:
    event_wait 48
