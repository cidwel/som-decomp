; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $18FA
.include "src/rom/event_command_macros.inc"
event_0B8_command_18FA:
    event_jump 1535
event_0B8_command_18FC:
    event_end 
