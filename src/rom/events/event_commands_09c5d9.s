; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C5D9
.include "src/rom/event_command_macros.inc"
event_2E2_command_C5D9:
    event_jump 1535
event_2E2_command_C5DB:
    event_end 
event_2E3_command_C5DC:
    event_test_flag_range 60, 0, 3
event_2E3_command_C5DF:
    event_jump 735
