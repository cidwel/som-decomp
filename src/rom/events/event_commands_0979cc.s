; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $79CC
.include "src/rom/event_command_macros.inc"
event_1D3_command_79CC:
    event_call 65
event_1D3_command_79CE:
    event_jump 1823
event_1D3_command_79D0:
    event_end 
event_1D4_command_79D1:
    event_test_flag_range 20, 4, 5
event_1D4_command_79D4:
    event_jump 469
