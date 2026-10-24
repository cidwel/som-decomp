; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $630D
.include "src/rom/event_command_macros.inc"
event_555_command_630D:
    event_test_flag_range 45, 5, 15
event_555_command_6310:
    event_jump 1367
event_555_command_6312:
    event_call 1149
event_555_command_6314:
    event_actor_walk 2, 0, 4
event_555_command_6317:
    event_wait_idle 
