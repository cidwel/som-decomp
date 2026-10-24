; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5CFC
.include "src/rom/event_command_macros.inc"
event_521_command_5CFC:
    event_jump 1535
event_521_command_5CFE:
    event_end 
event_522_command_5CFF:
    event_call 1236
event_522_command_5D01:
    event_jump 1535
event_522_command_5D03:
    event_end 
event_523_command_5D04:
    event_test_flag_range 53, 1, 15
event_523_command_5D07:
    event_jump 1328
