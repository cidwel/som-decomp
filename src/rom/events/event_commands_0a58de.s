; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $58DE
.include "src/rom/event_command_macros.inc"
event_501_command_58DE:
    event_jump 1289
event_501_command_58E0:
    event_end 
event_502_command_58E1:
    event_test_flag_range 186, 9, 15
event_502_command_58E4:
    event_jump 1288
event_502_command_58E6:
    event_increment_flag 186
event_502_command_58E8:
    event_test_flag_range 194, 0, 8
event_502_command_58EB:
    event_increment_flag 194
