; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8394
.include "src/rom/event_command_macros.inc"
event_1E6_command_8394:
    event_call 1051
event_1E6_command_8396:
    event_restore_hero 132
event_1E6_command_8398:
    event_end 
event_1E7_command_8399:
    event_test_flag_range 23, 4, 15
event_1E7_command_839C:
    event_jump 0
event_1E7_command_839E:
    event_actor_walk 0, 0, 32
event_1E7_command_83A1:
    event_wait_idle 
event_1E7_command_83A2:
    event_call 1151
