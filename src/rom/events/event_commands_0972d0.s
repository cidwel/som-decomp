; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $72D0
.include "src/rom/event_command_macros.inc"
event_1C9_command_72D0:
    event_wait 0
