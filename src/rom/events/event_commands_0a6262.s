; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6262
.include "src/rom/event_command_macros.inc"
event_543_command_6262:
    event_decrement_flag 255
event_543_command_6264:
    event_end 
event_544_command_6265:
    event_increment_flag 173
event_544_command_6267:
    event_set_flag 11, 2
event_544_command_626A:
    event_call 1984
event_544_command_626C:
    event_change_map 646
event_544_command_626E:
    event_call 1287
event_544_command_6270:
    event_jump 1346
event_544_command_6272:
    event_end 
event_545_command_6273:
    event_end 
event_546_command_6274:
    event_end 
event_547_command_6275:
    event_test_flag_range 173, 0, 0
event_547_command_6278:
    event_jump 1347
event_547_command_627A:
    event_change_map 646
event_547_command_627C:
    event_jump 1346
event_547_command_627E:
    event_end 
event_548_command_627F:
    event_end 
event_549_command_6280:
    event_end 
event_54A_command_6281:
    event_audio_request 2, 114, 15, 136
event_54A_command_6286:
    event_increment_flag 45
event_54A_command_6288:
    event_redraw_pieces 
event_54A_command_6289:
    event_return 
event_54A_command_628A:
    event_end 
event_54B_command_628B:
    event_change_map 786
event_54B_command_628D:
    event_end 
event_54C_command_628E:
    event_change_map 787
event_54C_command_6290:
    event_end 
event_54D_command_6291:
    event_test_flag_range 45, 4, 15
event_54D_command_6294:
    event_jump 1355
event_54D_command_6296:
    event_change_map 335
event_54D_command_6298:
    event_jump 1362
event_54D_command_629A:
    event_end 
event_54E_command_629B:
    event_test_flag_range 45, 4, 15
event_54E_command_629E:
    event_jump 1356
event_54E_command_62A0:
    event_change_map 336
event_54E_command_62A2:
    event_jump 1362
event_54E_command_62A4:
    event_end 
event_54F_command_62A5:
    event_test_flag_range 45, 1, 15
event_54F_command_62A8:
    event_jump 0
event_54F_command_62AA:
    event_call 1932
event_54F_command_62AC:
    event_call 1354
