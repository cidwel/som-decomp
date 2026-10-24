; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C583
.include "src/rom/event_command_macros.inc"
event_2E1_command_C583:
    event_jump 1535
event_2E1_command_C585:
    event_end 
event_2E2_command_C586:
    event_test_flag_range 60, 0, 3
event_2E2_command_C589:
    event_jump 735
