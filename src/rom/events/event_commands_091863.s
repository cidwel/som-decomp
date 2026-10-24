; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1863
.include "src/rom/event_command_macros.inc"
event_0B6_command_1863:
    event_jump 1535
event_0B6_command_1865:
    event_end 
