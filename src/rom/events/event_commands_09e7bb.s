; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E7BB
.include "src/rom/event_command_macros.inc"
event_3C6_command_E7BB:
    event_jump 1535
event_3C6_command_E7BD:
    event_end 
