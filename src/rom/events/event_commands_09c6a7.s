; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C6A7
.include "src/rom/event_command_macros.inc"
event_2E6_command_C6A7:
    event_jump 1535
event_2E6_command_C6A9:
    event_end 
event_2E7_command_C6AA:
    event_test_flag_range 60, 0, 3
event_2E7_command_C6AD:
    event_jump 735
