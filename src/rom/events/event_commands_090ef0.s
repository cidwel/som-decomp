; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0EF0
.include "src/rom/event_command_macros.inc"
event_031_command_0EF0:
    event_jump 1535
event_031_command_0EF2:
    event_end 
