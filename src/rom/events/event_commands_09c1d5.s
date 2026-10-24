; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C1D5
.include "src/rom/event_command_macros.inc"
event_2D5_command_C1D5:
    event_test_flag_range 60, 4, 4
event_2D5_command_C1D8:
    event_jump 1290
event_2D5_command_C1DA:
    event_jump 1535
event_2D5_command_C1DC:
    event_end 
event_2D6_command_C1DD:
    event_test_flag_range 60, 4, 4
event_2D6_command_C1E0:
    event_jump 765
event_2D6_command_C1E2:
    event_call 1151
event_2D6_command_C1E4:
    event_actor_walk 128, 1, 0
event_2D6_command_C1E7:
    event_wait_idle 
event_2D6_command_C1E8:
    event_call 96
