; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A0FC
.include "src/rom/event_command_macros.inc"
event_257_command_A0FC:
    event_jump 1535
event_257_command_A0FE:
    event_end 
event_258_command_A0FF:
    event_wait 0
