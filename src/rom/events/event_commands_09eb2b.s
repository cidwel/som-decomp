; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EB2B
.include "src/rom/event_command_macros.inc"
event_3D4_command_EB2B:
    event_jump 1535
event_3D4_command_EB2D:
    event_end 
