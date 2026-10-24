; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7DE3
.include "src/rom/event_command_macros.inc"
event_1DA_command_7DE3:
    event_wait 0
