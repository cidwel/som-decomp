; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A609
.include "src/rom/event_command_macros.inc"
event_272_command_A609:
    event_jump 1535
event_272_command_A60B:
    event_end 
