; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6144
.include "src/rom/event_command_macros.inc"
event_199_command_6144:
    event_jump 1535
event_199_command_6146:
    event_end 
