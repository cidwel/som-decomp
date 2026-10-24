; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $88C9
.include "src/rom/event_command_macros.inc"
event_63D_command_88C9:
    event_set_flag 147, 15
event_63D_command_88CC:
    event_jump 1535
event_63D_command_88CE:
    event_end 
event_63E_command_88CF:
    event_test_flag_range 44, 2, 15
event_63E_command_88D2:
    event_jump 0
event_63E_command_88D4:
    event_increment_flag 255
event_63E_command_88D6:
    event_freeze 
event_63E_command_88D7:
    event_actor_walk 0, 0, 63
event_63E_command_88DA:
    event_wait_idle 
event_63E_command_88DB:
    event_gather 
event_63E_command_88DC:
    event_set_flag 44, 2
event_63E_command_88DF:
    event_redraw_pieces 
event_63E_command_88E0:
    event_decrement_flag 255
event_63E_command_88E2:
    event_jump 1796
event_63E_command_88E4:
    event_end 
event_63F_command_88E5:
    event_test_flag_range 44, 3, 3
event_63F_command_88E8:
    event_jump 717
event_63F_command_88EA:
    event_end 
event_640_command_88EB:
    event_end 
event_641_command_88EC:
    event_call 1993
event_641_command_88EE:
    event_set_flag 172, 1
event_641_command_88F1:
    event_refresh_objects 
event_641_command_88F2:
    event_end 
event_642_command_88F3:
    event_test_flag_range 172, 0, 1
event_642_command_88F6:
    event_jump 1601
event_642_command_88F8:
    event_call 2002
event_642_command_88FA:
    event_end 
event_643_command_88FB:
    event_call 2002
event_643_command_88FD:
    event_end 
event_644_command_88FE:
    event_jump 1830
event_644_command_8900:
    event_end 
event_645_command_8901:
    event_end 
event_646_command_8902:
    event_jump 1792
event_646_command_8904:
    event_end 
event_647_command_8905:
    event_jump 1819
event_647_command_8907:
    event_end 
event_648_command_8908:
    event_set_flag 52, 14
event_648_command_890B:
    event_return 
event_648_command_890C:
    event_end 
event_649_command_890D:
    event_end 
event_64A_command_890E:
    event_end 
event_64B_command_890F:
    event_end 
event_64C_command_8910:
    event_end 
event_64D_command_8911:
    event_end 
event_64E_command_8912:
    event_end 
event_64F_command_8913:
    event_end 
event_650_command_8914:
    event_test_flag_range 23, 6, 15
event_650_command_8917:
    event_call 1617
event_650_command_8919:
    event_jump 1807
event_650_command_891B:
    event_end 
event_651_command_891C:
    event_test_flag_range 18, 6, 15
event_651_command_891F:
    event_return 
event_651_command_8920:
    event_noop 
event_651_command_8921:
    event_set_flag 18, 6
event_651_command_8924:
    event_return 
event_651_command_8925:
    event_end 
event_652_command_8926:
    event_end 
event_653_command_8927:
    event_end 
event_654_command_8928:
    event_end 
event_655_command_8929:
    event_end 
event_656_command_892A:
    event_end 
event_657_command_892B:
    event_end 
event_658_command_892C:
    event_screen 0
