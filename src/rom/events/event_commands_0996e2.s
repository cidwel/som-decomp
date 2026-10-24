; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $96E2
.include "src/rom/event_command_macros.inc"
event_220_command_96E2:
    event_jump 1535
event_220_command_96E4:
    event_end 
