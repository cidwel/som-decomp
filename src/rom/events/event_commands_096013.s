; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6013
.include "src/rom/event_command_macros.inc"
event_196_command_6013:
    event_jump 1535
event_196_command_6015:
    event_end 
