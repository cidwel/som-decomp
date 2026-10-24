; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82FD
.include "src/rom/event_command_macros.inc"
event_1E6_command_82FD:
    event_wait 0
