; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B5AA
.include "src/rom/event_command_macros.inc"
event_2A7_command_B5AA:
    event_wait 0
