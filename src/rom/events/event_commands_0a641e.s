; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $641E
.include "src/rom/event_command_macros.inc"
event_555_command_641E:
    event_wait 0
