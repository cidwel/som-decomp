; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7509
.include "src/rom/event_command_macros.inc"
event_1CB_command_7509:
    event_jump 1535
event_1CB_command_750B:
    event_end 
event_1CC_command_750C:
    event_test_flag_range 21, 4, 15
event_1CC_command_750F:
    event_jump 0
event_1CC_command_7511:
    event_freeze 
event_1CC_command_7512:
    event_actor_walk 0, 0, 48
event_1CC_command_7515:
    event_wait_idle 
event_1CC_command_7516:
    event_call 301
event_1CC_command_7518:
    event_actor_walk 4, 3, 32
