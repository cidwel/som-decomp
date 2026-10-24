; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $80AF
.include "src/rom/event_command_macros.inc"
event_5F8_command_80AF:
    event_decrement_flag 248
