; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82CA
.include "src/rom/event_command_macros.inc"
event_1E5_command_82CA:
    event_call 1939
event_1E5_command_82CC:
    event_change_map 80
event_1E5_command_82CE:
    event_jump 1558
event_1E5_command_82D0:
    event_end 
