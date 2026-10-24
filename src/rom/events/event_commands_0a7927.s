; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7927
.include "src/rom/event_command_macros.inc"
event_5DB_command_7927:
    event_decrement_flag 248
event_5DB_command_7929:
    event_jump 80
event_5DB_command_792B:
    event_end 
event_5DC_command_792C:
    event_jump 1499
event_5DC_command_792E:
    event_end 
event_5DD_command_792F:
    event_jump 1499
event_5DD_command_7931:
    event_end 
event_5DE_command_7932:
    event_test_flag_range 70, 0, 0
event_5DE_command_7935:
    event_jump 0
event_5DE_command_7937:
    event_change_map 886
event_5DE_command_7939:
    event_end 
event_5DF_command_793A:
    event_test_flag_range 70, 0, 0
event_5DF_command_793D:
    event_jump 0
event_5DF_command_793F:
    event_change_map 887
event_5DF_command_7941:
    event_end 
event_5E0_command_7942:
    event_test_flag_range 70, 0, 1
event_5E0_command_7945:
    event_jump 1499
event_5E0_command_7947:
    event_call 1498
event_5E0_command_7949:
    event_change_map 897
event_5E0_command_794B:
    event_end 
event_5E1_command_794C:
    event_test_flag_range 70, 0, 1
event_5E1_command_794F:
    event_jump 0
event_5E1_command_7951:
    event_change_map 896
event_5E1_command_7953:
    event_end 
event_5E2_command_7954:
    event_test_flag_range 70, 0, 2
event_5E2_command_7957:
    event_jump 0
event_5E2_command_7959:
    event_change_map 908
event_5E2_command_795B:
    event_end 
event_5E3_command_795C:
    event_test_flag_range 70, 0, 2
event_5E3_command_795F:
    event_jump 0
event_5E3_command_7961:
    event_change_map 909
event_5E3_command_7963:
    event_end 
event_5E4_command_7964:
    event_test_flag_range 70, 0, 3
event_5E4_command_7967:
    event_jump 1500
event_5E4_command_7969:
    event_call 1498
event_5E4_command_796B:
    event_change_map 919
event_5E4_command_796D:
    event_end 
event_5E5_command_796E:
    event_test_flag_range 70, 0, 3
event_5E5_command_7971:
    event_jump 0
event_5E5_command_7973:
    event_change_map 918
event_5E5_command_7975:
    event_end 
event_5E6_command_7976:
    event_test_flag_range 70, 0, 4
event_5E6_command_7979:
    event_jump 0
event_5E6_command_797B:
    event_change_map 934
event_5E6_command_797D:
    event_end 
event_5E7_command_797E:
    event_test_flag_range 70, 0, 4
event_5E7_command_7981:
    event_jump 0
event_5E7_command_7983:
    event_change_map 935
event_5E7_command_7985:
    event_end 
event_5E8_command_7986:
    event_test_flag_range 70, 0, 5
event_5E8_command_7989:
    event_jump 0
event_5E8_command_798B:
    event_change_map 942
event_5E8_command_798D:
    event_end 
event_5E9_command_798E:
    event_test_flag_range 70, 0, 1
event_5E9_command_7991:
    event_jump 1518
event_5E9_command_7993:
    event_change_map 41
event_5E9_command_7995:
    event_end 
event_5EA_command_7996:
    event_test_flag_range 70, 0, 3
event_5EA_command_7999:
    event_jump 1522
event_5EA_command_799B:
    event_change_map 43
event_5EA_command_799D:
    event_end 
event_5EB_command_799E:
    event_test_flag_range 70, 0, 5
event_5EB_command_79A1:
    event_jump 1526
event_5EB_command_79A3:
    event_change_map 46
event_5EB_command_79A5:
    event_end 
event_5EC_command_79A6:
    event_test_flag_range 70, 0, 0
event_5EC_command_79A9:
    event_call 1988
event_5EC_command_79AB:
    event_end 
event_5ED_command_79AC:
    event_call 1051
event_5ED_command_79AE:
    event_call 1282
event_5ED_command_79B0:
    event_increment_flag 70
event_5ED_command_79B2:
    event_jump 1578
event_5ED_command_79B4:
    event_end 
event_5EE_command_79B5:
    event_change_map 895
event_5EE_command_79B7:
    event_call 1988
event_5EE_command_79B9:
    event_end 
event_5EF_command_79BA:
    event_call 1285
event_5EF_command_79BC:
    event_increment_flag 70
event_5EF_command_79BE:
    event_jump 1578
event_5EF_command_79C0:
    event_end 
event_5F0_command_79C1:
    event_test_flag_range 70, 0, 2
event_5F0_command_79C4:
    event_call 1988
event_5F0_command_79C6:
    event_end 
event_5F1_command_79C7:
    event_call 1287
event_5F1_command_79C9:
    event_increment_flag 70
event_5F1_command_79CB:
    event_redraw_pieces 
event_5F1_command_79CC:
    event_jump 1578
event_5F1_command_79CE:
    event_end 
event_5F2_command_79CF:
    event_change_map 917
event_5F2_command_79D1:
    event_call 1988
event_5F2_command_79D3:
    event_end 
event_5F3_command_79D4:
    event_call 1280
event_5F3_command_79D6:
    event_increment_flag 70
event_5F3_command_79D8:
    event_jump 1578
event_5F3_command_79DA:
    event_end 
event_5F4_command_79DB:
    event_test_flag_range 70, 0, 4
event_5F4_command_79DE:
    event_call 1988
event_5F4_command_79E0:
    event_end 
event_5F5_command_79E1:
    event_call 1281
event_5F5_command_79E3:
    event_increment_flag 70
event_5F5_command_79E5:
    event_redraw_pieces 
event_5F5_command_79E6:
    event_jump 1578
event_5F5_command_79E8:
    event_end 
event_5F6_command_79E9:
    event_change_map 941
event_5F6_command_79EB:
    event_call 1988
event_5F6_command_79ED:
    event_end 
event_5F7_command_79EE:
    event_increment_flag 70
event_5F7_command_79F0:
    event_call 1286
event_5F7_command_79F2:
    event_jump 1578
event_5F7_command_79F4:
    event_end 
event_5F8_command_79F5:
    event_test_flag_range 70, 0, 5
event_5F8_command_79F8:
    event_jump 1501
event_5F8_command_79FA:
    event_call 1498
event_5F8_command_79FC:
    event_freeze 
event_5F8_command_79FD:
    event_gather 
event_5F8_command_79FE:
    event_call 1836
event_5F8_command_7A00:
    event_toggle_visibility_04 
event_5F8_command_7A01:
    event_change_map 94
event_5F8_command_7A03:
    event_increment_flag 1
event_5F8_command_7A05:
    event_actor_walk 4, 1, 0
event_5F8_command_7A08:
    event_wait_idle 
