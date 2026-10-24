; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4C63
.include "src/rom/event_command_macros.inc"
event_167_command_4C63:
    event_screen 8
