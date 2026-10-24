; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $58C2
.include "src/rom/event_command_macros.inc"
event_500_command_58C2:
    event_jump 1289
event_500_command_58C4:
    event_end 
event_501_command_58C5:
    event_test_flag_range 185, 8, 15
event_501_command_58C8:
    event_jump 1288
event_501_command_58CA:
    event_increment_flag 185
event_501_command_58CC:
    event_test_flag_range 193, 0, 7
event_501_command_58CF:
    event_increment_flag 193
