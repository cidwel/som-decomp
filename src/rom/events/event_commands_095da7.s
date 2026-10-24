; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5DA7
.include "src/rom/event_command_macros.inc"
event_191_command_5DA7:
    event_jump 1535
event_191_command_5DA9:
    event_end 
