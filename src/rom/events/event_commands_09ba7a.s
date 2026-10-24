; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BA7A
.include "src/rom/event_command_macros.inc"
event_2B7_command_BA7A:
    event_wait 0
