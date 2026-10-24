; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $601A
.include "src/rom/event_command_macros.inc"
event_52F_command_601A:
    event_jump 1812
event_52F_command_601C:
    event_end 
