; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E08B
.include "src/rom/event_command_macros.inc"
event_3A1_command_E08B:
    event_jump 1535
event_3A1_command_E08D:
    event_end 
event_3A2_command_E08E:
    event_actor_walk 128, 0, 0
event_3A2_command_E091:
    event_wait_idle 
event_3A2_command_E092:
    event_actor_animation_loop 128, 129
event_3A2_command_E095:
    event_wait 32
event_3A2_command_E097:
    event_increment_flag 49
event_3A2_command_E099:
    event_refresh_objects 
event_3A2_command_E09A:
    event_end 
event_3A3_command_E09B:
    event_test_flag_range 48, 2, 15
event_3A3_command_E09E:
    event_jump 932
event_3A3_command_E0A0:
    event_jump 1457
event_3A3_command_E0A2:
    event_end 
event_3A4_command_E0A3:
    event_freeze 
event_3A4_command_E0A4:
    event_test_flag_range 10, 1, 15
event_3A4_command_E0A7:
    event_jump 933
event_3A4_command_E0A9:
    event_call 1152
event_3A4_command_E0AB:
    event_test_flag_range 90, 3, 15
event_3A4_command_E0AE:
    event_jump 934
