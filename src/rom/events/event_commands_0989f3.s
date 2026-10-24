; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $89F3
.include "src/rom/event_command_macros.inc"
event_1F6_command_89F3:
    event_increment_flag 217
event_1F6_command_89F5:
    event_test_flag_range 17, 12, 12
event_1F6_command_89F8:
    event_increment_flag 17
event_1F6_command_89FA:
    event_wait 8
event_1F6_command_89FC:
    event_increment_flag 248
