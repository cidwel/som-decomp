; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0D03
.include "src/rom/event_command_macros.inc"
event_02C_command_0D03:
    event_wait 0
