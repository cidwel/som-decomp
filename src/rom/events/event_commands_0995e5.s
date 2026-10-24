; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $95E5
.include "src/rom/event_command_macros.inc"
event_219_command_95E5:
    event_jump 1535
event_219_command_95E7:
    event_end 
event_21A_command_95E8:
    event_end 
event_21B_command_95E9:
    event_end 
event_21C_command_95EA:
    event_test_flag_range 13, 0, 0
event_21C_command_95ED:
    event_jump 541
event_21C_command_95EF:
    event_test_flag_range 14, 0, 0
event_21C_command_95F2:
    event_jump 542
event_21C_command_95F4:
    event_jump 543
event_21C_command_95F6:
    event_end 
