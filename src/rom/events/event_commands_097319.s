; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7319
.include "src/rom/event_command_macros.inc"
event_1C9_command_7319:
    event_jump 1535
event_1C9_command_731B:
    event_end 
event_1CA_command_731C:
    event_test_flag_range 21, 5, 15
event_1CA_command_731F:
    event_jump 459
event_1CA_command_7321:
    event_freeze 
event_1CA_command_7322:
    event_gather 
event_1CA_command_7323:
    event_screen 8
event_1CA_command_7325:
    event_actor_walk 4, 1, 0
event_1CA_command_7328:
    event_actor_animation_loop 5, 164
