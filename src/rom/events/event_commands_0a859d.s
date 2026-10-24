; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $859D
.include "src/rom/event_command_macros.inc"
event_5FE_command_859D:
    event_return 
event_5FE_command_859E:
    event_end 
event_5FF_command_859F:
    event_wait 0
