; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EA0D
.include "src/rom/event_command_macros.inc"
event_3D0_command_EA0D:
    event_jump 1535
event_3D0_command_EA0F:
    event_end 
