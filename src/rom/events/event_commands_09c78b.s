; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C78B
.include "src/rom/event_command_macros.inc"
event_2E9_command_C78B:
    event_jump 1535
event_2E9_command_C78D:
    event_end 
