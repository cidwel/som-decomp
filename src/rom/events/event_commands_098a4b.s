; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A4B
.include "src/rom/event_command_macros.inc"
event_1F6_command_8A4B:
    event_decrement_flag 248
