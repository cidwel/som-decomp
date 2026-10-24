; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $460E
.include "src/rom/event_command_macros.inc"
event_147_command_460E:
    event_test_flag_range 26, 8, 15
event_147_command_4611:
    event_jump 1535
