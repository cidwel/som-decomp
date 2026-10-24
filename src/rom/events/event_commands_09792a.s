; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $792A
.include "src/rom/event_command_macros.inc"
event_1D1_command_792A:
    event_decrement_flag 47
event_1D1_command_792C:
    event_test_flag_range 47, 1, 15
event_1D1_command_792F:
    event_jump 465
event_1D1_command_7931:
    event_wait 16
