; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4973
.include "src/rom/event_command_macros.inc"
event_155_command_4973:
    event_test_flag_range 18, 0, 5
event_155_command_4976:
    event_jump 1535
