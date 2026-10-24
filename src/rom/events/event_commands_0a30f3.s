; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $30F3
.include "src/rom/event_command_macros.inc"
event_4E1_command_30F3:
    event_decrement_flag 248
