; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6619
.include "src/rom/event_command_macros.inc"
event_1B1_command_6619:
    event_test_flag_range 20, 0, 0
event_1B1_command_661C:
    event_increment_flag 20
event_1B1_command_661E:
    event_end 
event_1B2_command_661F:
    event_set_flag 15, 0
event_1B2_command_6622:
    event_object_command_37 100
