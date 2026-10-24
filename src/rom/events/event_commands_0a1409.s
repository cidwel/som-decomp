; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1409
.include "src/rom/event_command_macros.inc"
event_429_command_1409:
    event_decrement_flag 255
event_429_command_140B:
    event_end 
event_42A_command_140C:
    event_call 1841
event_42A_command_140E:
    event_end 
event_42B_command_140F:
    event_call 1841
event_42B_command_1411:
    event_end 
event_42C_command_1412:
    event_call 1841
event_42C_command_1414:
    event_end 
event_42D_command_1415:
    event_freeze 
