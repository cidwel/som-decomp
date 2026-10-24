; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C6CA
.include "src/rom/event_command_macros.inc"
event_2E7_command_C6CA:
    event_jump 1535
event_2E7_command_C6CC:
    event_end 
