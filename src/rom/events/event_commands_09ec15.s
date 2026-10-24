; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC15
.include "src/rom/event_command_macros.inc"
event_3D9_command_EC15:
    event_jump 574
event_3D9_command_EC17:
    event_end 
