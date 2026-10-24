; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $37AB
.include "src/rom/event_command_macros.inc"
event_118_command_37AB:
    event_jump 1535
event_118_command_37AD:
    event_end 
