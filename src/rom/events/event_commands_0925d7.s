; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $25D7
.include "src/rom/event_command_macros.inc"
event_101_command_25D7:
    event_call 1865
event_101_command_25D9:
    event_end 
event_102_command_25DA:
    event_test_flag_range 16, 1, 15
event_102_command_25DD:
    event_jump 0
event_102_command_25DF:
    event_screen_word 6, 17407
event_102_command_25E3:
    event_actor_walk 0, 1, 0
