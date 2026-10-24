; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85B2
.include "src/rom/event_command_macros.inc"
event_600_command_85B2:
    event_call 1547
event_600_command_85B4:
    event_jump 1535
event_600_command_85B6:
    event_end 
