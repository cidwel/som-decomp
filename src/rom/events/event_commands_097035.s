; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7035
.include "src/rom/event_command_macros.inc"
event_1C1_command_7035:
    event_jump 1535
event_1C1_command_7037:
    event_end 
