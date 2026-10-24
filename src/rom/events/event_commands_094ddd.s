; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4DDD
.include "src/rom/event_command_macros.inc"
event_169_command_4DDD:
    event_jump 1535
event_169_command_4DDF:
    event_end 
event_16A_command_4DE0:
    event_test_flag_range 26, 0, 7
event_16A_command_4DE3:
    event_jump 361
event_16A_command_4DE5:
    event_change_map 49
event_16A_command_4DE7:
    event_end 
event_16B_command_4DE8:
    event_test_flag_range 26, 0, 7
event_16B_command_4DEB:
    event_jump 361
event_16B_command_4DED:
    event_change_map 51
event_16B_command_4DEF:
    event_end 
event_16C_command_4DF0:
    event_test_flag_range 26, 3, 15
event_16C_command_4DF3:
    event_jump 0
event_16C_command_4DF5:
    event_end 
event_16D_command_4DF6:
    event_freeze 
event_16D_command_4DF7:
    event_screen 8
