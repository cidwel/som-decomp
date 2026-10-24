; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6A12
.include "src/rom/event_command_macros.inc"
event_55E_command_6A12:
    event_wait 32
event_55E_command_6A14:
    event_call 89
event_55E_command_6A16:
    event_screen_word 6, 65535
event_55E_command_6A1A:
    event_wait 48
event_55E_command_6A1C:
    event_increment_flag 58
event_55E_command_6A1E:
    event_refresh_objects 
event_55E_command_6A1F:
    event_call 1149
event_55E_command_6A21:
    event_screen 7
event_55E_command_6A23:
    event_call 2007
event_55E_command_6A25:
    event_wait 32
event_55E_command_6A27:
    event_end 
event_55F_command_6A28:
    event_end 
event_560_command_6A29:
    event_test_flag_range 66, 0, 0
event_560_command_6A2C:
    event_jump 1387
event_560_command_6A2E:
    event_end 
event_561_command_6A2F:
    event_test_flag_range 66, 1, 1
event_561_command_6A32:
    event_jump 1387
event_561_command_6A34:
    event_end 
event_562_command_6A35:
    event_test_flag_range 66, 2, 2
event_562_command_6A38:
    event_jump 1387
event_562_command_6A3A:
    event_end 
event_563_command_6A3B:
    event_test_flag_range 66, 4, 4
event_563_command_6A3E:
    event_jump 1387
event_563_command_6A40:
    event_end 
event_564_command_6A41:
    event_test_flag_range 66, 5, 5
event_564_command_6A44:
    event_jump 1387
event_564_command_6A46:
    event_end 
event_565_command_6A47:
    event_call 7
event_565_command_6A49:
    event_test_flag_range 66, 0, 2
event_565_command_6A4C:
    event_jump 0
event_565_command_6A4E:
    event_test_flag_range 66, 4, 15
event_565_command_6A51:
    event_jump 0
event_565_command_6A53:
    event_test_flag_range 67, 0, 0
event_565_command_6A56:
    event_jump 1386
event_565_command_6A58:
    event_jump 1385
event_565_command_6A5A:
    event_end 
event_566_command_6A5B:
    event_call 7
event_566_command_6A5D:
    event_test_flag_range 66, 0, 2
event_566_command_6A60:
    event_jump 0
event_566_command_6A62:
    event_test_flag_range 66, 4, 15
event_566_command_6A65:
    event_jump 0
event_566_command_6A67:
    event_test_flag_range 67, 1, 1
event_566_command_6A6A:
    event_jump 1386
event_566_command_6A6C:
    event_jump 1385
event_566_command_6A6E:
    event_end 
event_567_command_6A6F:
    event_call 7
event_567_command_6A71:
    event_test_flag_range 66, 0, 2
event_567_command_6A74:
    event_jump 0
event_567_command_6A76:
    event_test_flag_range 66, 4, 15
event_567_command_6A79:
    event_jump 0
event_567_command_6A7B:
    event_test_flag_range 67, 2, 2
event_567_command_6A7E:
    event_jump 1386
event_567_command_6A80:
    event_jump 1385
event_567_command_6A82:
    event_end 
event_568_command_6A83:
    event_call 7
event_568_command_6A85:
    event_test_flag_range 66, 0, 2
event_568_command_6A88:
    event_jump 0
event_568_command_6A8A:
    event_test_flag_range 66, 4, 15
event_568_command_6A8D:
    event_jump 0
event_568_command_6A8F:
    event_test_flag_range 67, 3, 3
event_568_command_6A92:
    event_jump 1387
event_568_command_6A94:
    event_jump 1385
event_568_command_6A96:
    event_end 
event_569_command_6A97:
    event_call 1945
event_569_command_6A99:
    event_set_flag 67, 0
event_569_command_6A9C:
    event_redraw_pieces 
event_569_command_6A9D:
    event_end 
event_56A_command_6A9E:
    event_call 1941
event_56A_command_6AA0:
    event_increment_flag 67
event_56A_command_6AA2:
    event_redraw_pieces 
event_56A_command_6AA3:
    event_end 
event_56B_command_6AA4:
    event_set_flag 67, 0
event_56B_command_6AA7:
    event_redraw_pieces 
event_56B_command_6AA8:
    event_call 1944
event_56B_command_6AAA:
    event_increment_flag 66
event_56B_command_6AAC:
    event_redraw_pieces 
event_56B_command_6AAD:
    event_end 
