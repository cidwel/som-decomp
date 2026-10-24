; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C563
.include "src/rom/event_command_macros.inc"
event_2E0_command_C563:
    event_jump 1535
event_2E0_command_C565:
    event_end 
event_2E1_command_C566:
    event_test_flag_range 60, 0, 3
event_2E1_command_C569:
    event_jump 735
