; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AB0F
.include "src/rom/event_command_macros.inc"
event_28B_command_AB0F:
    event_wait 8
event_28B_command_AB11:
    event_call 82
event_28B_command_AB13:
    event_call 86
event_28B_command_AB15:
    event_wait 0
