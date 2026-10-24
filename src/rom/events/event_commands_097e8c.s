; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7E8C
.include "src/rom/event_command_macros.inc"
event_1DA_command_7E8C:
    event_increment_flag 22
event_1DA_command_7E8E:
    event_call 64
event_1DA_command_7E90:
    event_call 1939
event_1DA_command_7E92:
    event_change_map 80
event_1DA_command_7E94:
    event_jump 1558
event_1DA_command_7E96:
    event_end 
event_1DB_command_7E97:
    event_test_flag_range 23, 1, 15
event_1DB_command_7E9A:
    event_jump 0
event_1DB_command_7E9C:
    event_call 1937
event_1DB_command_7E9E:
    event_call 1932
event_1DB_command_7EA0:
    event_set_flag 23, 1
event_1DB_command_7EA3:
    event_redraw_pieces 
event_1DB_command_7EA4:
    event_end 
event_1DC_command_7EA5:
    event_test_flag_range 23, 2, 15
event_1DC_command_7EA8:
    event_jump 0
event_1DC_command_7EAA:
    event_freeze 
event_1DC_command_7EAB:
    event_gather 
event_1DC_command_7EAC:
    event_call 1151
event_1DC_command_7EAE:
    event_set_flag 23, 2
event_1DC_command_7EB1:
    event_call 1932
event_1DC_command_7EB3:
    event_redraw_pieces 
