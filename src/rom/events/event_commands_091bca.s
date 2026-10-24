; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1BCA
.include "src/rom/event_command_macros.inc"
event_0D0_command_1BCA:
    event_jump 255
event_0D0_command_1BCC:
    event_jump 236
event_0D0_command_1BCE:
    event_jump 237
event_0D0_command_1BD0:
    event_end 
event_0D1_command_1BD1:
    event_test_flag_range 30, 7, 7
event_0D1_command_1BD4:
    event_increment_flag 30
event_0D1_command_1BD6:
    event_set_flag 15, 0
event_0D1_command_1BD9:
    event_call 1032
