; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EAB3
.include "src/rom/event_command_macros.inc"
event_3D3_command_EAB3:
    event_jump 1535
event_3D3_command_EAB5:
    event_end 
