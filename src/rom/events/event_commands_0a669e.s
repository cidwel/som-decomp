; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $669E
.include "src/rom/event_command_macros.inc"
event_558_command_669E:
    event_increment_flag 248
