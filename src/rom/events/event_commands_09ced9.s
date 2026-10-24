; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CED9
.include "src/rom/event_command_macros.inc"
event_331_command_CED9:
    event_jump 79
event_331_command_CEDB:
    event_jump 818
event_331_command_CEDD:
    event_jump 79
event_331_command_CEDF:
    event_end 
event_332_command_CEE0:
    event_set_flag 112, 0
event_332_command_CEE3:
    event_set_flag 113, 0
event_332_command_CEE6:
    event_set_flag 114, 0
event_332_command_CEE9:
    event_test_flag_range 12, 1, 1
event_332_command_CEEC:
    event_call 820
event_332_command_CEEE:
    event_test_flag_range 13, 1, 1
event_332_command_CEF1:
    event_call 821
event_332_command_CEF3:
    event_test_flag_range 14, 1, 1
event_332_command_CEF6:
    event_call 822
event_332_command_CEF8:
    event_set_flag 15, 0
event_332_command_CEFB:
    event_test_flag_range 249, 0, 0
event_332_command_CEFE:
    event_call 832
event_332_command_CF00:
    event_test_flag_range 249, 1, 1
event_332_command_CF03:
    event_call 833
event_332_command_CF05:
    event_test_flag_range 249, 2, 2
event_332_command_CF08:
    event_call 834
event_332_command_CF0A:
    event_test_flag_range 249, 3, 3
event_332_command_CF0D:
    event_call 835
event_332_command_CF0F:
    event_test_flag_range 249, 4, 4
event_332_command_CF12:
    event_call 836
event_332_command_CF14:
    event_test_flag_range 249, 5, 5
event_332_command_CF17:
    event_call 837
event_332_command_CF19:
    event_test_flag_range 249, 6, 6
event_332_command_CF1C:
    event_call 838
event_332_command_CF1E:
    event_test_flag_range 249, 7, 7
event_332_command_CF21:
    event_call 839
event_332_command_CF23:
    event_test_flag_range 249, 8, 15
event_332_command_CF26:
    event_call 840
event_332_command_CF28:
    event_test_flag_range 15, 0, 0
event_332_command_CF2B:
    event_jump 1157
event_332_command_CF2D:
    event_jump 823
event_332_command_CF2F:
    event_end 
event_333_command_CF30:
    event_actor_walk 3, 2, 12
event_333_command_CF33:
    event_return 
event_333_command_CF34:
    event_end 
event_334_command_CF35:
    event_test_actor_field 1, 1, 145, 128
event_334_command_CF39:
    event_increment_flag 112
event_334_command_CF3B:
    event_return 
event_334_command_CF3C:
    event_end 
event_335_command_CF3D:
    event_test_actor_field 1, 2, 145, 128
event_335_command_CF41:
    event_increment_flag 113
event_335_command_CF43:
    event_return 
event_335_command_CF44:
    event_end 
event_336_command_CF45:
    event_test_actor_field 1, 3, 145, 128
event_336_command_CF49:
    event_increment_flag 114
event_336_command_CF4B:
    event_return 
event_336_command_CF4C:
    event_end 
