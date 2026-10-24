; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5CE1
.include "src/rom/event_command_macros.inc"
event_520_command_5CE1:
    event_jump 1535
event_520_command_5CE3:
    event_end 
event_521_command_5CE4:
    event_call 1236
