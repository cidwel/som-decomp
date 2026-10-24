; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EA4D
.include "src/rom/event_command_macros.inc"
event_3D1_command_EA4D:
    event_jump 1535
event_3D1_command_EA4F:
    event_end 
