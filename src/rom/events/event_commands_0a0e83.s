; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E83
.include "src/rom/event_command_macros.inc"
event_409_command_0E83:
    event_jump 1535
event_409_command_0E85:
    event_end 
event_40A_command_0E86:
    event_end 
event_40B_command_0E87:
    event_end 
event_40C_command_0E88:
    event_end 
event_40D_command_0E89:
    event_end 
event_40E_command_0E8A:
    event_end 
event_40F_command_0E8B:
    event_end 
event_410_command_0E8C:
    event_set_actor_field 1, 144, 0
event_410_command_0E90:
    event_set_actor_field 1, 145, 0
event_410_command_0E94:
    event_set_actor_field 2, 144, 0
event_410_command_0E98:
    event_set_actor_field 2, 145, 0
event_410_command_0E9C:
    event_set_actor_field 3, 144, 0
event_410_command_0EA0:
    event_set_actor_field 3, 145, 0
event_410_command_0EA4:
    event_restore_hero 68
event_410_command_0EA6:
    event_return 
event_410_command_0EA7:
    event_end 
event_411_command_0EA8:
    event_set_actor_field 1, 144, 0
event_411_command_0EAC:
    event_set_actor_field 1, 145, 0
event_411_command_0EB0:
    event_return 
event_411_command_0EB1:
    event_end 
event_412_command_0EB2:
    event_set_actor_field 2, 144, 0
event_412_command_0EB6:
    event_set_actor_field 2, 145, 0
event_412_command_0EBA:
    event_return 
event_412_command_0EBB:
    event_end 
event_413_command_0EBC:
    event_set_actor_field 3, 144, 0
event_413_command_0EC0:
    event_set_actor_field 3, 145, 0
event_413_command_0EC4:
    event_return 
event_413_command_0EC5:
    event_end 
event_414_command_0EC6:
    event_set_actor_field 1, 144, 0
event_414_command_0ECA:
    event_set_actor_field 2, 144, 0
event_414_command_0ECE:
    event_set_actor_field 3, 144, 0
event_414_command_0ED2:
    event_restore_hero 68
event_414_command_0ED4:
    event_return 
event_414_command_0ED5:
    event_end 
event_415_command_0ED6:
    event_set_actor_field 1, 144, 0
event_415_command_0EDA:
    event_restore_hero 65
event_415_command_0EDC:
    event_return 
event_415_command_0EDD:
    event_end 
event_416_command_0EDE:
    event_set_actor_field 2, 144, 0
event_416_command_0EE2:
    event_restore_hero 66
event_416_command_0EE4:
    event_return 
event_416_command_0EE5:
    event_end 
event_417_command_0EE6:
    event_set_actor_field 3, 144, 0
event_417_command_0EEA:
    event_restore_hero 67
event_417_command_0EEC:
    event_return 
event_417_command_0EED:
    event_end 
event_418_command_0EEE:
    event_set_actor_field 1, 144, 0
event_418_command_0EF2:
    event_set_actor_field 1, 145, 0
event_418_command_0EF6:
    event_restore_hero 65
event_418_command_0EF8:
    event_return 
event_418_command_0EF9:
    event_end 
event_419_command_0EFA:
    event_set_actor_field 2, 144, 0
event_419_command_0EFE:
    event_set_actor_field 2, 145, 0
event_419_command_0F02:
    event_restore_hero 66
event_419_command_0F04:
    event_return 
event_419_command_0F05:
    event_end 
event_41A_command_0F06:
    event_set_actor_field 3, 144, 0
event_41A_command_0F0A:
    event_set_actor_field 3, 145, 0
event_41A_command_0F0E:
    event_restore_hero 67
event_41A_command_0F10:
    event_return 
event_41A_command_0F11:
    event_end 
event_41B_command_0F12:
    event_freeze 
event_41B_command_0F13:
    event_actor_animation_loop 1, 171
event_41B_command_0F16:
    event_actor_animation_loop 2, 171
event_41B_command_0F19:
    event_actor_animation_loop 3, 171
event_41B_command_0F1C:
    event_set_actor_field 1, 144, 0
event_41B_command_0F20:
    event_set_actor_field 1, 145, 0
event_41B_command_0F24:
    event_set_actor_field 2, 144, 0
event_41B_command_0F28:
    event_set_actor_field 2, 145, 0
event_41B_command_0F2C:
    event_set_actor_field 3, 144, 0
event_41B_command_0F30:
    event_set_actor_field 3, 145, 0
event_41B_command_0F34:
    event_restore_hero 4
event_41B_command_0F36:
    event_restore_hero 68
event_41B_command_0F38:
    event_audio_request 2, 7, 0, 136
event_41B_command_0F3D:
    event_native_command_35 
event_41B_command_0F3E:
    event_return 
event_41B_command_0F3F:
    event_end 
event_41C_command_0F40:
    event_test_flag_range 112, 0, 0
event_41C_command_0F43:
    event_restore_hero 1
event_41C_command_0F45:
    event_test_flag_range 113, 0, 0
event_41C_command_0F48:
    event_restore_hero 2
event_41C_command_0F4A:
    event_test_flag_range 114, 0, 0
event_41C_command_0F4D:
    event_restore_hero 3
event_41C_command_0F4F:
    event_test_flag_range 113, 0, 0
event_41C_command_0F52:
    event_restore_hero 130
event_41C_command_0F54:
    event_test_flag_range 114, 0, 0
event_41C_command_0F57:
    event_restore_hero 131
event_41C_command_0F59:
    event_audio_request 2, 7, 0, 136
event_41C_command_0F5E:
    event_native_command_35 
event_41C_command_0F5F:
    event_return 
event_41C_command_0F60:
    event_end 
event_41D_command_0F61:
    event_end 
event_41E_command_0F62:
    event_set_actor_field 1, 144, 0
event_41E_command_0F66:
    event_set_actor_field 1, 145, 0
event_41E_command_0F6A:
    event_set_actor_field 2, 144, 0
event_41E_command_0F6E:
    event_set_actor_field 2, 145, 0
event_41E_command_0F72:
    event_set_actor_field 3, 144, 0
event_41E_command_0F76:
    event_set_actor_field 3, 145, 0
event_41E_command_0F7A:
    event_restore_hero 4
event_41E_command_0F7C:
    event_restore_hero 132
event_41E_command_0F7E:
    event_restore_hero 68
event_41E_command_0F80:
    event_native_command_35 
event_41E_command_0F81:
    event_return 
event_41E_command_0F82:
    event_end 
event_41F_command_0F83:
    event_end 
event_420_command_0F84:
    event_test_flag_range 78, 0, 0
event_420_command_0F87:
    event_jump 1057
event_420_command_0F89:
    event_change_map 147
event_420_command_0F8B:
    event_end 
event_421_command_0F8C:
    event_increment_flag 78
event_421_command_0F8E:
    event_change_map 339
event_421_command_0F90:
    event_jump 1796
event_421_command_0F92:
    event_end 
event_422_command_0F93:
    event_increment_flag 78
event_422_command_0F95:
    event_call 1841
event_422_command_0F97:
    event_change_map 147
event_422_command_0F99:
    event_end 
event_423_command_0F9A:
    event_test_flag_range 78, 0, 2
event_423_command_0F9D:
    event_jump 1060
event_423_command_0F9F:
    event_change_map 192
event_423_command_0FA1:
    event_end 
event_424_command_0FA2:
    event_increment_flag 78
event_424_command_0FA4:
    event_set_flag 11, 15
event_424_command_0FA7:
    event_change_map 338
event_424_command_0FA9:
    event_jump 1796
event_424_command_0FAB:
    event_end 
event_425_command_0FAC:
    event_increment_flag 78
event_425_command_0FAE:
    event_set_flag 11, 2
event_425_command_0FB1:
    event_call 1841
event_425_command_0FB3:
    event_change_map 192
event_425_command_0FB5:
    event_jump 1068
event_425_command_0FB7:
    event_end 
event_426_command_0FB8:
    event_test_flag_range 78, 8, 15
event_426_command_0FBB:
    event_jump 1065
event_426_command_0FBD:
    event_change_map 59
event_426_command_0FBF:
    event_end 
event_427_command_0FC0:
    event_end 
event_428_command_0FC1:
    event_test_flag_range 78, 6, 15
event_428_command_0FC4:
    event_jump 0
event_428_command_0FC6:
    event_jump 112
event_428_command_0FC8:
    event_end 
event_429_command_0FC9:
    event_test_flag_range 78, 0, 7
event_429_command_0FCC:
    event_jump 0
event_429_command_0FCE:
    event_change_map 59
event_429_command_0FD0:
    event_call 1148
event_429_command_0FD2:
    event_call 1847
event_429_command_0FD4:
    event_screen_word 6, 16
event_429_command_0FD8:
    event_screen 2
event_429_command_0FDA:
    event_wait 8
event_429_command_0FDC:
    event_screen 3
event_429_command_0FDE:
    event_wait 16
