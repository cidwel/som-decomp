; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EF0B
.include "src/rom/event_command_macros.inc"
event_3E5_command_EF0B:
    event_jump 1535
event_3E5_command_EF0D:
    event_end 
