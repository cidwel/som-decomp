; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $83DD
.include "src/rom/event_command_macros.inc"
event_1E7_command_83DD:
    event_wait 0
