; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $122C
.include "src/rom/event_command_macros.inc"
event_064_command_122C:
    event_jump 79
event_064_command_122E:
    event_jump 818
event_064_command_1230:
    event_jump 79
event_064_command_1232:
    event_end 
