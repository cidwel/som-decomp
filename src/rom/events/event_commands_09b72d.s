; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B72D
.include "src/rom/event_command_macros.inc"
event_2AE_command_B72D:
    event_jump 1535
event_2AE_command_B72F:
    event_end 
