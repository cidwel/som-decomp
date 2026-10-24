; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6342
.include "src/rom/event_command_macros.inc"
event_555_command_6342:
    event_wait 0
