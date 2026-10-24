; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $580E
.include "src/rom/event_command_macros.inc"
event_4FD_command_580E:
    event_call 88
event_4FD_command_5810:
    event_call 1864
event_4FD_command_5812:
    event_wait 8
event_4FD_command_5814:
    event_set_flag 247, 12
event_4FD_command_5817:
    event_wait 8
event_4FD_command_5819:
    event_set_flag 247, 10
event_4FD_command_581C:
    event_wait 8
event_4FD_command_581E:
    event_set_flag 247, 8
event_4FD_command_5821:
    event_wait 8
event_4FD_command_5823:
    event_set_flag 247, 6
event_4FD_command_5826:
    event_wait 8
event_4FD_command_5828:
    event_set_flag 247, 4
event_4FD_command_582B:
    event_actor_walk 1, 0, 0
event_4FD_command_582E:
    event_actor_walk 4, 0, 0
event_4FD_command_5831:
    event_actor_walk 5, 0, 0
event_4FD_command_5834:
    event_actor_walk 6, 0, 0
event_4FD_command_5837:
    event_actor_walk 7, 0, 0
event_4FD_command_583A:
    event_wait_idle 
event_4FD_command_583B:
    event_wait 9
event_4FD_command_583D:
    event_decrement_flag 247
event_4FD_command_583F:
    event_wait 10
event_4FD_command_5841:
    event_decrement_flag 247
event_4FD_command_5843:
    event_wait 11
event_4FD_command_5845:
    event_decrement_flag 247
event_4FD_command_5847:
    event_wait 12
event_4FD_command_5849:
    event_set_flag 247, 0
event_4FD_command_584C:
    event_actor_walk 1, 0, 0
event_4FD_command_584F:
    event_actor_walk 4, 0, 0
event_4FD_command_5852:
    event_actor_walk 5, 0, 0
event_4FD_command_5855:
    event_actor_walk 6, 0, 0
event_4FD_command_5858:
    event_actor_walk 7, 0, 0
event_4FD_command_585B:
    event_wait_idle 
event_4FD_command_585C:
    event_call 1850
event_4FD_command_585E:
    event_change_map 64
event_4FD_command_5860:
    event_actor_walk 1, 2, 63
event_4FD_command_5863:
    event_wait_idle 
event_4FD_command_5864:
    event_actor_walk 1, 2, 63
event_4FD_command_5867:
    event_wait_idle 
event_4FD_command_5868:
    event_actor_walk 1, 2, 16
event_4FD_command_586B:
    event_wait_idle 
event_4FD_command_586C:
    event_actor_walk 1, 0, 63
event_4FD_command_586F:
    event_wait_idle 
event_4FD_command_5870:
    event_actor_walk 1, 3, 0
event_4FD_command_5873:
    event_wait_idle 
event_4FD_command_5874:
    event_screen_word 6, 16383
event_4FD_command_5878:
    event_wait 48
event_4FD_command_587A:
    event_increment_flag 104
event_4FD_command_587C:
    event_refresh_objects 
event_4FD_command_587D:
    event_screen 7
event_4FD_command_587F:
    event_wait 48
event_4FD_command_5881:
    event_wait 48
event_4FD_command_5883:
    event_screen_word 6, 16383
event_4FD_command_5887:
    event_wait 48
event_4FD_command_5889:
    event_toggle_visibility_04 
event_4FD_command_588A:
    event_change_map 620
event_4FD_command_588C:
    event_actor_animation 4, 175
event_4FD_command_588F:
    event_wait_idle 
event_4FD_command_5890:
    event_actor_walk 1, 0, 63
event_4FD_command_5893:
    event_wait_idle 
event_4FD_command_5894:
    event_actor_walk 1, 0, 63
event_4FD_command_5897:
    event_wait_idle 
event_4FD_command_5898:
    event_wait 64
event_4FD_command_589A:
    event_actor_animation 4, 150
event_4FD_command_589D:
    event_wait_idle 
event_4FD_command_589E:
    event_screen_word 6, 65535
event_4FD_command_58A2:
    event_wait 64
event_4FD_command_58A4:
    event_jump 71
event_4FD_command_58A6:
    event_end 
event_4FE_command_58A7:
    event_end 
event_4FF_command_58A8:
    event_end 
event_500_command_58A9:
    event_test_flag_range 184, 9, 15
event_500_command_58AC:
    event_jump 1288
event_500_command_58AE:
    event_increment_flag 184
event_500_command_58B0:
    event_test_flag_range 192, 0, 8
event_500_command_58B3:
    event_increment_flag 192
