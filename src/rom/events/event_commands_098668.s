; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8668
.include "src/rom/event_command_macros.inc"
event_1E7_command_8668:
    event_actor_walk 4, 1, 0
event_1E7_command_866B:
    event_wait_idle 
event_1E7_command_866C:
    event_actor_animation_loop 4, 129
event_1E7_command_866F:
    event_wait_idle 
event_1E7_command_8670:
    event_wait 16
event_1E7_command_8672:
    event_actor_animation_loop 4, 130
event_1E7_command_8675:
    event_wait_idle 
event_1E7_command_8676:
    event_wait 16
event_1E7_command_8678:
    event_increment_flag 23
event_1E7_command_867A:
    event_refresh_objects 
event_1E7_command_867B:
    event_actor_walk 0, 0, 32
event_1E7_command_867E:
    event_wait_idle 
event_1E7_command_867F:
    event_screen 8
event_1E7_command_8681:
    event_wait 32
event_1E7_command_8683:
    event_call 496
event_1E7_command_8685:
    event_wait 12
event_1E7_command_8687:
    event_call 496
event_1E7_command_8689:
    event_wait 12
event_1E7_command_868B:
    event_call 496
event_1E7_command_868D:
    event_wait 12
event_1E7_command_868F:
    event_change_map 314
event_1E7_command_8691:
    event_jump 1796
event_1E7_command_8693:
    event_end 
event_1E8_command_8694:
    event_test_flag_range 83, 2, 15
event_1E8_command_8697:
    event_jump 0
event_1E8_command_8699:
    event_call 1925
event_1E8_command_869B:
    event_increment_flag 83
event_1E8_command_869D:
    event_redraw_pieces 
event_1E8_command_869E:
    event_increment_flag 83
event_1E8_command_86A0:
    event_redraw_pieces 
event_1E8_command_86A1:
    event_increment_flag 83
event_1E8_command_86A3:
    event_redraw_pieces 
event_1E8_command_86A4:
    event_increment_flag 83
event_1E8_command_86A6:
    event_redraw_pieces 
event_1E8_command_86A7:
    event_increment_flag 83
event_1E8_command_86A9:
    event_redraw_pieces 
event_1E8_command_86AA:
    event_increment_flag 83
event_1E8_command_86AC:
    event_redraw_pieces 
event_1E8_command_86AD:
    event_call 1928
event_1E8_command_86AF:
    event_call 1923
event_1E8_command_86B1:
    event_end 
event_1E9_command_86B2:
    event_test_flag_range 83, 1, 15
event_1E9_command_86B5:
    event_jump 0
event_1E9_command_86B7:
    event_test_flag_range 23, 0, 1
event_1E9_command_86BA:
    event_jump 500
event_1E9_command_86BC:
    event_freeze 
event_1E9_command_86BD:
    event_gather 
event_1E9_command_86BE:
    event_audio_request 2, 114, 15, 136
event_1E9_command_86C3:
    event_call 496
event_1E9_command_86C5:
    event_end 
