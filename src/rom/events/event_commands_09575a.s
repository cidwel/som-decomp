; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $575A
.include "src/rom/event_command_macros.inc"
event_181_command_575A:
    event_test_flag_range 23, 0, 5
event_181_command_575D:
    event_jump 19
event_181_command_575F:
    event_test_flag_range 19, 0, 4
event_181_command_5762:
    event_jump 1535
event_181_command_5764:
    event_wait 0
