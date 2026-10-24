; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B039
.include "src/rom/event_command_macros.inc"
event_29A_command_B039:
    event_jump 1535
event_29A_command_B03B:
    event_end 
event_29B_command_B03C:
    event_call 1151
