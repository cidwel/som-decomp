; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3069
.include "src/rom/event_command_macros.inc"
event_4E1_command_3069:
    event_decrement_flag 248
