; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1C3B
.include "src/rom/event_command_macros.inc"
event_4AC_command_1C3B:
    event_test_flag_range 71, 3, 15
event_4AC_command_1C3E:
    event_jump 1209
event_4AC_command_1C40:
    event_test_flag_range 65, 2, 15
event_4AC_command_1C43:
    event_jump 1195
