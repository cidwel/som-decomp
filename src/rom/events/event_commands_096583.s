; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6583
.include "src/rom/event_command_macros.inc"
event_1B0_command_6583:
    event_screen 8
