; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A1B
.include "src/rom/event_command_macros.inc"
event_4A3_command_1A1B:
    event_increment_flag 248
