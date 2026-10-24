; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4DC0
.include "src/rom/event_command_macros.inc"
event_168_command_4DC0:
    event_jump 1535
event_168_command_4DC2:
    event_end 
event_169_command_4DC3:
    event_freeze 
event_169_command_4DC4:
    event_gather 
event_169_command_4DC5:
    event_call 96
