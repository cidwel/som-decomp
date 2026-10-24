; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D26A
.include "src/rom/event_command_macros.inc"
event_364_command_D26A:
    event_jump 1535
event_364_command_D26C:
    event_end 
