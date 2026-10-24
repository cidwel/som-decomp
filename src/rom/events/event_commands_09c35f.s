; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C35F
.include "src/rom/event_command_macros.inc"
event_2D7_command_C35F:
    event_jump 1535
event_2D7_command_C361:
    event_end 
