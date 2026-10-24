; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D9A6
.include "src/rom/event_command_macros.inc"
event_385_command_D9A6:
    event_jump 1535
event_385_command_D9A8:
    event_end 
