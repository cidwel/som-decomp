; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8469
.include "src/rom/event_command_macros.inc"
event_5F8_command_8469:
    event_call 1864
event_5F8_command_846B:
    event_wait 32
event_5F8_command_846D:
    event_call 1987
