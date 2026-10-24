; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $37A7
.include "src/rom/event_command_macros.inc"
event_4E3_command_37A7:
    event_decrement_flag 248
event_4E3_command_37A9:
    event_call 2006
