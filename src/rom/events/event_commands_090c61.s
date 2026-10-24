; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0C61
.include "src/rom/event_command_macros.inc"
event_029_command_0C61:
    event_call 1051
event_029_command_0C63:
    event_jump 1535
event_029_command_0C65:
    event_end 
