; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9B3C
.include "src/rom/event_command_macros.inc"
event_22F_command_9B3C:
    event_change_map 308
event_22F_command_9B3E:
    event_end 
event_230_command_9B3F:
    event_call 1998
event_230_command_9B41:
    event_call 1933
event_230_command_9B43:
    event_end 
event_231_command_9B44:
    event_test_flag_range 17, 0, 12
event_231_command_9B47:
    event_jump 174
event_231_command_9B49:
    event_change_map 320
event_231_command_9B4B:
    event_test_flag_range 169, 1, 15
event_231_command_9B4E:
    event_jump 1803
event_231_command_9B50:
    event_call 1997
event_231_command_9B52:
    event_end 
event_232_command_9B53:
    event_test_flag_range 169, 0, 0
event_232_command_9B56:
    event_jump 565
event_232_command_9B58:
    event_jump 1803
event_232_command_9B5A:
    event_end 
event_233_command_9B5B:
    event_call 1280
event_233_command_9B5D:
    event_call 1924
event_233_command_9B5F:
    event_set_flag 169, 1
event_233_command_9B62:
    event_redraw_pieces 
event_233_command_9B63:
    event_jump 1803
event_233_command_9B65:
    event_end 
event_234_command_9B66:
    event_jump 1803
event_234_command_9B68:
    event_end 
event_235_command_9B69:
    event_increment_flag 255
event_235_command_9B6B:
    event_freeze 
event_235_command_9B6C:
    event_actor_walk 0, 0, 48
event_235_command_9B6F:
    event_wait_idle 
event_235_command_9B70:
    event_gather 
event_235_command_9B71:
    event_screen 8
