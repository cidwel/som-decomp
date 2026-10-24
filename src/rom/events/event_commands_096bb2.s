; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6BB2
.include "src/rom/event_command_macros.inc"
event_1B7_command_6BB2:
    event_end 
event_1B8_command_6BB3:
    event_set_flag 253, 0
event_1B8_command_6BB6:
    event_set_flag 254, 5
event_1B8_command_6BB9:
    event_test_flag_range 96, 4, 15
event_1B8_command_6BBC:
    event_call 1999
event_1B8_command_6BBE:
    event_test_flag_range 21, 5, 5
event_1B8_command_6BC1:
    event_jump 446
event_1B8_command_6BC3:
    event_end 
event_1B9_command_6BC4:
    event_call 1283
event_1B9_command_6BC6:
    event_freeze 
event_1B9_command_6BC7:
    event_increment_flag 20
event_1B9_command_6BC9:
    event_call 1999
event_1B9_command_6BCB:
    event_change_map 81
event_1B9_command_6BCD:
    event_freeze 
