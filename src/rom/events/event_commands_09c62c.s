; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C62C
.include "src/rom/event_command_macros.inc"
event_2E4_command_C62C:
    event_wait 0
