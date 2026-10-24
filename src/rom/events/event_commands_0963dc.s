; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $63DC
.include "src/rom/event_command_macros.inc"
event_1A5_command_63DC:
    event_test_flag_range 18, 10, 15
event_1A5_command_63DF:
    event_jump 1535
event_1A5_command_63E1:
    event_wait 0
