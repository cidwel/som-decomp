; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EFA5
.include "src/rom/event_command_macros.inc"
event_3E8_command_EFA5:
    event_jump 1535
event_3E8_command_EFA7:
    event_end 
event_3E9_command_EFA8:
    event_call 1008
