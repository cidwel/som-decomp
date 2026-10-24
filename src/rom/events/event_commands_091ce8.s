; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1CE8
.include "src/rom/event_command_macros.inc"
event_0D5_command_1CE8:
    event_end 
event_0D6_command_1CE9:
    event_end 
event_0D7_command_1CEA:
    event_end 
event_0D8_command_1CEB:
    event_end 
event_0D9_command_1CEC:
    event_end 
event_0DA_command_1CED:
    event_test_flag_range 18, 9, 15
event_0DA_command_1CF0:
    event_jump 773
event_0DA_command_1CF2:
    event_jump 334
event_0DA_command_1CF4:
    event_end 
event_0DB_command_1CF5:
    event_test_flag_range 18, 9, 15
event_0DB_command_1CF8:
    event_jump 770
event_0DB_command_1CFA:
    event_set_flag 250, 2
