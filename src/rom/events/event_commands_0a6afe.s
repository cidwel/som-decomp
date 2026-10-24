; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6AFE
.include "src/rom/event_command_macros.inc"
event_56C_command_6AFE:
    event_jump 1535
event_56C_command_6B00:
    event_end 
event_56D_command_6B01:
    event_end 
event_56E_command_6B02:
    event_end 
event_56F_command_6B03:
    event_end 
event_570_command_6B04:
    event_call 848
event_570_command_6B06:
    event_test_flag_range 152, 0, 0
event_570_command_6B09:
    event_jump 0
event_570_command_6B0B:
    event_increment_flag 232
event_570_command_6B0D:
    event_jump 1400
event_570_command_6B0F:
    event_end 
event_571_command_6B10:
    event_call 849
event_571_command_6B12:
    event_test_flag_range 153, 0, 0
event_571_command_6B15:
    event_jump 0
event_571_command_6B17:
    event_increment_flag 233
event_571_command_6B19:
    event_jump 1400
event_571_command_6B1B:
    event_end 
event_572_command_6B1C:
    event_call 850
event_572_command_6B1E:
    event_test_flag_range 154, 0, 0
event_572_command_6B21:
    event_jump 0
event_572_command_6B23:
    event_increment_flag 234
event_572_command_6B25:
    event_jump 1400
event_572_command_6B27:
    event_end 
event_573_command_6B28:
    event_call 851
event_573_command_6B2A:
    event_test_flag_range 155, 0, 0
event_573_command_6B2D:
    event_jump 0
event_573_command_6B2F:
    event_increment_flag 235
event_573_command_6B31:
    event_jump 1400
event_573_command_6B33:
    event_end 
event_574_command_6B34:
    event_call 852
event_574_command_6B36:
    event_test_flag_range 156, 0, 0
event_574_command_6B39:
    event_jump 0
event_574_command_6B3B:
    event_increment_flag 236
event_574_command_6B3D:
    event_jump 1400
event_574_command_6B3F:
    event_end 
event_575_command_6B40:
    event_call 853
event_575_command_6B42:
    event_test_flag_range 157, 0, 0
event_575_command_6B45:
    event_jump 0
event_575_command_6B47:
    event_increment_flag 237
event_575_command_6B49:
    event_jump 1400
event_575_command_6B4B:
    event_end 
event_576_command_6B4C:
    event_call 854
event_576_command_6B4E:
    event_test_flag_range 158, 0, 0
event_576_command_6B51:
    event_jump 0
event_576_command_6B53:
    event_increment_flag 238
event_576_command_6B55:
    event_jump 1400
event_576_command_6B57:
    event_end 
event_577_command_6B58:
    event_call 855
event_577_command_6B5A:
    event_test_flag_range 159, 0, 0
event_577_command_6B5D:
    event_jump 0
event_577_command_6B5F:
    event_increment_flag 239
event_577_command_6B61:
    event_jump 1400
event_577_command_6B63:
    event_end 
event_578_command_6B64:
    event_call 1922
event_578_command_6B66:
    event_refresh_objects 
event_578_command_6B67:
    event_call 1944
