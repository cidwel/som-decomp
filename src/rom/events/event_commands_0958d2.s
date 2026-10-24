; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $58D2
.include "src/rom/event_command_macros.inc"
event_184_command_58D2:
    event_jump 1535
event_184_command_58D4:
    event_end 
