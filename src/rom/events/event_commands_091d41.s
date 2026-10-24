; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1D41
.include "src/rom/event_command_macros.inc"
event_0DB_command_1D41:
    event_jump 213
event_0DB_command_1D43:
    event_jump 786
event_0DB_command_1D45:
    event_jump 787
event_0DB_command_1D47:
    event_end 
event_0DC_command_1D48:
    event_test_flag_range 18, 9, 15
event_0DC_command_1D4B:
    event_jump 801
event_0DC_command_1D4D:
    event_freeze 
event_0DC_command_1D4E:
    event_gather 
event_0DC_command_1D4F:
    event_screen 8
event_0DC_command_1D51:
    event_set_flag 249, 1
