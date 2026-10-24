; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $62CA
.include "src/rom/event_command_macros.inc"
event_54F_command_62CA:
    event_jump 1535
event_54F_command_62CC:
    event_end 
event_550_command_62CD:
    event_test_flag_range 45, 2, 15
event_550_command_62D0:
    event_jump 0
event_550_command_62D2:
    event_call 1935
event_550_command_62D4:
    event_call 1354
