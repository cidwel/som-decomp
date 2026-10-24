; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EB6E
.include "src/rom/event_command_macros.inc"
event_3D5_command_EB6E:
    event_jump 1535
event_3D5_command_EB70:
    event_end 
