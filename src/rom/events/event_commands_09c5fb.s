; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C5FB
.include "src/rom/event_command_macros.inc"
event_2E3_command_C5FB:
    event_jump 1535
event_2E3_command_C5FD:
    event_end 
event_2E4_command_C5FE:
    event_test_flag_range 60, 0, 3
event_2E4_command_C601:
    event_jump 735
