; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $627E
.include "src/rom/event_command_macros.inc"
event_1A0_command_627E:
    event_wait 0
