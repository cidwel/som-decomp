; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9718
.include "src/rom/event_command_macros.inc"
event_7F3_command_9718:
    event_return 
event_7F3_command_9719:
    event_end 
event_7F4_command_971A:
    event_toggle_visibility_04 
event_7F4_command_971B:
    event_change_map 117
event_7F4_command_971D:
    event_return 
event_7F4_command_971E:
    event_end 
event_7F5_command_971F:
    event_actor_animation_loop 1, 170
event_7F5_command_9722:
    event_return 
event_7F5_command_9723:
    event_end 
event_7F6_command_9724:
    event_actor_animation_loop 2, 170
event_7F6_command_9727:
    event_return 
event_7F6_command_9728:
    event_end 
event_7F7_command_9729:
    event_actor_animation_loop 3, 170
event_7F7_command_972C:
    event_return 
event_7F7_command_972D:
    event_end 
event_7F8_command_972E:
    event_freeze 
event_7F8_command_972F:
    event_call 1864
event_7F8_command_9731:
    event_screen_word 6, 32767
event_7F8_command_9735:
    event_wait 40
event_7F8_command_9737:
    event_audio_request 1, 24, 68, 143
event_7F8_command_973C:
    event_set_flag 112, 0
event_7F8_command_973F:
    event_set_flag 113, 0
event_7F8_command_9742:
    event_set_flag 114, 0
event_7F8_command_9745:
    event_test_flag_range 12, 1, 1
event_7F8_command_9748:
    event_call 820
event_7F8_command_974A:
    event_test_flag_range 13, 1, 1
event_7F8_command_974D:
    event_call 821
event_7F8_command_974F:
    event_test_flag_range 14, 1, 1
event_7F8_command_9752:
    event_call 822
event_7F8_command_9754:
    event_test_flag_range 112, 0, 0
event_7F8_command_9757:
    event_call 1048
event_7F8_command_9759:
    event_test_flag_range 113, 0, 0
event_7F8_command_975C:
    event_call 1049
event_7F8_command_975E:
    event_test_flag_range 114, 0, 0
event_7F8_command_9761:
    event_call 1050
event_7F8_command_9763:
    event_test_flag_range 78, 6, 6
event_7F8_command_9766:
    event_jump 2041
event_7F8_command_9768:
    event_test_flag_range 112, 0, 0
event_7F8_command_976B:
    event_call 2037
event_7F8_command_976D:
    event_test_flag_range 113, 0, 0
event_7F8_command_9770:
    event_call 2038
event_7F8_command_9772:
    event_test_flag_range 114, 0, 0
event_7F8_command_9775:
    event_call 2039
event_7F8_command_9777:
    event_screen 7
event_7F8_command_9779:
    event_wait 64
event_7F8_command_977B:
    event_call 1984
