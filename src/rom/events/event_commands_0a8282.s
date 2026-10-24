; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8282
.include "src/rom/event_command_macros.inc"
event_5F8_command_8282:
    event_call 1922
event_5F8_command_8284:
    event_call 1922
event_5F8_command_8286:
    event_call 1922
event_5F8_command_8288:
    event_set_flag 193, 8
event_5F8_command_828B:
    event_set_flag 185, 7
