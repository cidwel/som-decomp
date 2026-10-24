; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EBE9
.include "src/rom/event_command_macros.inc"
event_3D8_command_EBE9:
    event_jump 1535
event_3D8_command_EBEB:
    event_end 
