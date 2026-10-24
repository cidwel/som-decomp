; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BD95
.include "src/rom/event_command_macros.inc"
event_2C3_command_BD95:
    event_return 
event_2C3_command_BD96:
    event_end 
event_2C4_command_BD97:
    event_call 852
event_2C4_command_BD99:
    event_test_flag_range 156, 1, 1
event_2C4_command_BD9C:
    event_jump 709
event_2C4_command_BD9E:
    event_end 
event_2C5_command_BD9F:
    event_increment_flag 59
event_2C5_command_BDA1:
    event_change_map 618
event_2C5_command_BDA3:
    event_jump 1594
event_2C5_command_BDA5:
    event_end 
event_2C6_command_BDA6:
    event_test_flag_range 59, 0, 1
event_2C6_command_BDA9:
    event_change_map 566
event_2C6_command_BDAB:
    event_test_flag_range 59, 2, 15
event_2C6_command_BDAE:
    event_change_map 569
event_2C6_command_BDB0:
    event_jump 1594
event_2C6_command_BDB2:
    event_end 
event_2C7_command_BDB3:
    event_test_flag_range 59, 0, 1
event_2C7_command_BDB6:
    event_change_map 567
event_2C7_command_BDB8:
    event_test_flag_range 59, 2, 15
event_2C7_command_BDBB:
    event_change_map 570
event_2C7_command_BDBD:
    event_jump 1594
event_2C7_command_BDBF:
    event_end 
event_2C8_command_BDC0:
    event_call 851
event_2C8_command_BDC2:
    event_test_flag_range 155, 2, 2
event_2C8_command_BDC5:
    event_jump 713
event_2C8_command_BDC7:
    event_call 849
event_2C8_command_BDC9:
    event_test_flag_range 153, 1, 1
event_2C8_command_BDCC:
    event_jump 716
event_2C8_command_BDCE:
    event_end 
event_2C9_command_BDCF:
    event_increment_flag 44
event_2C9_command_BDD1:
    event_refresh_objects 
event_2C9_command_BDD2:
    event_redraw_pieces 
event_2C9_command_BDD3:
    event_screen 7
