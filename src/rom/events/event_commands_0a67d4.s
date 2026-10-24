; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $67D4
.include "src/rom/event_command_macros.inc"
event_55C_command_67D4:
    event_jump 1535
event_55C_command_67D6:
    event_end 
event_55D_command_67D7:
    event_freeze 
event_55D_command_67D8:
    event_gather 
event_55D_command_67D9:
    event_call 96
