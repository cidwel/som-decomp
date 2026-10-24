; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5D30
.include "src/rom/event_command_macros.inc"
event_523_command_5D30:
    event_jump 1535
event_523_command_5D32:
    event_end 
