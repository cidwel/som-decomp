; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9D5B
.include "src/rom/event_command_macros.inc"
event_23B_command_9D5B:
    event_jump 566
event_23B_command_9D5D:
    event_end 
