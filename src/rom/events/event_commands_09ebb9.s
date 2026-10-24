; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EBB9
.include "src/rom/event_command_macros.inc"
event_3D7_command_EBB9:
    event_jump 1535
event_3D7_command_EBBB:
    event_end 
