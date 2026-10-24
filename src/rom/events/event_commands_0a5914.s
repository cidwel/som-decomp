; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5914
.include "src/rom/event_command_macros.inc"
event_503_command_5914:
    event_jump 1289
event_503_command_5916:
    event_end 
event_504_command_5917:
    event_test_flag_range 188, 9, 15
event_504_command_591A:
    event_jump 1288
event_504_command_591C:
    event_increment_flag 188
event_504_command_591E:
    event_test_flag_range 196, 0, 8
event_504_command_5921:
    event_increment_flag 196
