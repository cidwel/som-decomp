; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $833B
.include "src/rom/event_command_macros.inc"
event_5F8_command_833B:
    event_decrement_flag 248
