; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $70CD
.include "src/rom/event_command_macros.inc"
event_1C3_command_70CD:
    event_jump 1535
event_1C3_command_70CF:
    event_end 
