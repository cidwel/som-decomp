; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C681
.include "src/rom/event_command_macros.inc"
event_2E5_command_C681:
    event_jump 1535
event_2E5_command_C683:
    event_end 
event_2E6_command_C684:
    event_test_flag_range 60, 0, 3
event_2E6_command_C687:
    event_jump 735
