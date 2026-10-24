; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EB9F
.include "src/rom/event_command_macros.inc"
event_3D6_command_EB9F:
    event_jump 1535
event_3D6_command_EBA1:
    event_end 
