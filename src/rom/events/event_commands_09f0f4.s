; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F0F4
.include "src/rom/event_command_macros.inc"
event_3EC_command_F0F4:
    event_jump 1535
event_3EC_command_F0F6:
    event_end 
event_3ED_command_F0F7:
    event_call 1008
