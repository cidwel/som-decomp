; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4936
.include "src/rom/event_command_macros.inc"
event_154_command_4936:
    event_jump 1535
event_154_command_4938:
    event_end 
event_155_command_4939:
    event_test_flag_range 18, 7, 8
event_155_command_493C:
    event_jump 344
event_155_command_493E:
    event_test_flag_range 18, 9, 15
event_155_command_4941:
    event_jump 375
