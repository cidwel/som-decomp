; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BAAF
.include "src/rom/event_command_macros.inc"
event_2B7_command_BAAF:
    event_test_flag_range 39, 4, 15
event_2B7_command_BAB2:
    event_jump 196
event_2B7_command_BAB4:
    event_jump 1535
event_2B7_command_BAB6:
    event_end 
