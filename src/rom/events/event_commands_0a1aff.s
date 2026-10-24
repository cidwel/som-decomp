; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1AFF
.include "src/rom/event_command_macros.inc"
event_4A4_command_1AFF:
    event_decrement_flag 255
event_4A4_command_1B01:
    event_change_map 1015
event_4A4_command_1B03:
    event_call 1148
event_4A4_command_1B05:
    event_actor_animation_loop 1, 138
event_4A4_command_1B08:
    event_actor_animation_loop 2, 138
event_4A4_command_1B0B:
    event_actor_animation_loop 3, 138
event_4A4_command_1B0E:
    event_wait_idle 
event_4A4_command_1B0F:
    event_wait 2
event_4A4_command_1B11:
    event_call 1822
event_4A4_command_1B13:
    event_increment_flag 68
event_4A4_command_1B15:
    event_set_flag 65, 3
event_4A4_command_1B18:
    event_party_command 4
event_4A4_command_1B1A:
    event_end 
event_4A5_command_1B1B:
    event_screen_word 6, 30313
event_4A5_command_1B1F:
    event_wait 4
event_4A5_command_1B21:
    event_screen 7
event_4A5_command_1B23:
    event_wait 4
event_4A5_command_1B25:
    event_screen_word 6, 4535
event_4A5_command_1B29:
    event_wait 4
event_4A5_command_1B2B:
    event_screen 7
event_4A5_command_1B2D:
    event_wait 4
event_4A5_command_1B2F:
    event_screen_word 6, 30418
event_4A5_command_1B33:
    event_wait 4
event_4A5_command_1B35:
    event_screen 7
event_4A5_command_1B37:
    event_wait 4
event_4A5_command_1B39:
    event_screen_word 6, 31
event_4A5_command_1B3D:
    event_wait 4
event_4A5_command_1B3F:
    event_screen 7
event_4A5_command_1B41:
    event_wait 4
event_4A5_command_1B43:
    event_screen_word 6, 1023
event_4A5_command_1B47:
    event_wait 4
event_4A5_command_1B49:
    event_screen 7
event_4A5_command_1B4B:
    event_wait 4
event_4A5_command_1B4D:
    event_screen_word 6, 992
event_4A5_command_1B51:
    event_wait 4
event_4A5_command_1B53:
    event_screen 7
event_4A5_command_1B55:
    event_wait 4
event_4A5_command_1B57:
    event_screen_word 6, 6342
event_4A5_command_1B5B:
    event_wait 4
event_4A5_command_1B5D:
    event_screen 7
event_4A5_command_1B5F:
    event_wait 4
event_4A5_command_1B61:
    event_screen_word 6, 32767
event_4A5_command_1B65:
    event_wait 4
event_4A5_command_1B67:
    event_screen 7
event_4A5_command_1B69:
    event_wait 4
event_4A5_command_1B6B:
    event_return 
event_4A5_command_1B6C:
    event_end 
event_4A6_command_1B6D:
    event_end 
event_4A7_command_1B6E:
    event_end 
event_4A8_command_1B6F:
    event_end 
event_4A9_command_1B70:
    event_end 
event_4AA_command_1B71:
    event_test_flag_range 68, 3, 15
event_4AA_command_1B74:
    event_jump 0
event_4AA_command_1B76:
    event_freeze 
event_4AA_command_1B77:
    event_gather 
event_4AA_command_1B78:
    event_call 96
event_4AA_command_1B7A:
    event_call 1151
event_4AA_command_1B7C:
    event_call 2012
event_4AA_command_1B7E:
    event_increment_flag 68
