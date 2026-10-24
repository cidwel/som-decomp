; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85C4
.include "src/rom/event_command_macros.inc"
event_601_command_85C4:
    event_call 1547
event_601_command_85C6:
    event_jump 1535
event_601_command_85C8:
    event_end 
