; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2BC0
.include "src/rom/event_command_macros.inc"
event_108_command_2BC0:
    event_jump 1535
event_108_command_2BC2:
    event_end 
