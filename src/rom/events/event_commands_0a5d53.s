; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5D53
.include "src/rom/event_command_macros.inc"
event_524_command_5D53:
    event_jump 1535
event_524_command_5D55:
    event_end 
event_525_command_5D56:
    event_test_flag_range 53, 1, 15
event_525_command_5D59:
    event_jump 1329
