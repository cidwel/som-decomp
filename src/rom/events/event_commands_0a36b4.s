; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $36B4
.include "src/rom/event_command_macros.inc"
event_4E2_command_36B4:
    event_jump 595
event_4E2_command_36B6:
    event_end 
event_4E3_command_36B7:
    event_test_flag_range 36, 3, 7
event_4E3_command_36BA:
    event_jump 630
event_4E3_command_36BC:
    event_test_flag_range 36, 8, 9
event_4E3_command_36BF:
    event_jump 631
event_4E3_command_36C1:
    event_test_flag_range 36, 10, 15
event_4E3_command_36C4:
    event_jump 633
