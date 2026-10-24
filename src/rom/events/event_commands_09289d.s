; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $289D
.include "src/rom/event_command_macros.inc"
event_105_command_289D:
    event_jump 1806
event_105_command_289F:
    event_end 
event_106_command_28A0:
    event_call 1853
event_106_command_28A2:
    event_audio_request 1, 28, 74, 47
event_106_command_28A7:
    event_call 1933
event_106_command_28A9:
    event_freeze 
