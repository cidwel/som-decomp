; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4DAC
.include "src/rom/event_command_macros.inc"
event_167_command_4DAC:
    event_jump 1535
event_167_command_4DAE:
    event_end 
event_168_command_4DAF:
    event_increment_flag 26
event_168_command_4DB1:
    event_freeze 
