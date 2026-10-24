; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B989
.include "src/rom/event_command_macros.inc"
event_2B4_command_B989:
    event_test_flag_range 41, 1, 1
event_2B4_command_B98C:
    event_jump 703
event_2B4_command_B98E:
    event_test_flag_range 41, 2, 15
event_2B4_command_B991:
    event_jump 698
event_2B4_command_B993:
    event_test_flag_range 147, 1, 2
event_2B4_command_B996:
    event_jump 702
event_2B4_command_B998:
    event_test_flag_range 38, 6, 6
event_2B4_command_B99B:
    event_jump 685
