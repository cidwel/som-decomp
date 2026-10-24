; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $756B
.include "src/rom/event_command_macros.inc"
event_1CC_command_756B:
    event_actor_walk 0, 1, 32
event_1CC_command_756E:
    event_wait_idle 
event_1CC_command_756F:
    event_actor_walk 0, 2, 0
event_1CC_command_7572:
    event_test_flag_range 5, 1, 15
event_1CC_command_7575:
    event_call 529
