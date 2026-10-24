; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A91
.include "src/rom/event_command_macros.inc"
event_4A3_command_1A91:
    event_decrement_flag 248
