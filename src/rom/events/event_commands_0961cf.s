; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $61CF
.include "src/rom/event_command_macros.inc"
event_19B_command_61CF:
    event_jump 1535
event_19B_command_61D1:
    event_end 
