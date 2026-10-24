; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2F1A
.include "src/rom/event_command_macros.inc"
event_4E1_command_2F1A:
    event_call 2010
event_4E1_command_2F1C:
    event_increment_flag 248
