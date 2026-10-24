; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6FC2
.include "src/rom/event_command_macros.inc"
event_1C0_command_6FC2:
    event_jump 1535
event_1C0_command_6FC4:
    event_end 
