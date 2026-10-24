; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $39F4
.include "src/rom/event_command_macros.inc"
event_123_command_39F4:
    event_test_flag_range 17, 0, 0
event_123_command_39F7:
    event_call 521
event_123_command_39F9:
    event_set_flag 84, 0
event_123_command_39FC:
    event_actor_walk 4, 0, 16
event_123_command_39FF:
    event_wait_idle 
event_123_command_3A00:
    event_call 1935
event_123_command_3A02:
    event_set_flag 17, 3
event_123_command_3A05:
    event_refresh_objects 
event_123_command_3A06:
    event_end 
event_124_command_3A07:
    event_call 2002
event_124_command_3A09:
    event_test_flag_range 17, 4, 15
event_124_command_3A0C:
    event_jump 1780
event_124_command_3A0E:
    event_actor_walk 4, 0, 63
event_124_command_3A11:
    event_wait_idle 
event_124_command_3A12:
    event_increment_flag 17
event_124_command_3A14:
    event_refresh_objects 
event_124_command_3A15:
    event_jump 1780
event_124_command_3A17:
    event_end 
event_125_command_3A18:
    event_test_flag_range 17, 5, 15
event_125_command_3A1B:
    event_jump 0
event_125_command_3A1D:
    event_actor_walk 4, 3, 63
event_125_command_3A20:
    event_wait_idle 
event_125_command_3A21:
    event_actor_walk 0, 3, 63
event_125_command_3A24:
    event_actor_walk 4, 3, 63
event_125_command_3A27:
    event_wait_idle 
event_125_command_3A28:
    event_actor_walk 0, 3, 16
event_125_command_3A2B:
    event_actor_walk 4, 0, 63
event_125_command_3A2E:
    event_wait_idle 
event_125_command_3A2F:
    event_actor_walk 0, 0, 0
event_125_command_3A32:
    event_increment_flag 17
event_125_command_3A34:
    event_refresh_objects 
event_125_command_3A35:
    event_end 
