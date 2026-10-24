; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $58F8
.include "src/rom/event_command_macros.inc"
event_502_command_58F8:
    event_jump 1289
event_502_command_58FA:
    event_end 
event_503_command_58FB:
    event_test_flag_range 187, 9, 15
event_503_command_58FE:
    event_jump 1288
event_503_command_5900:
    event_increment_flag 187
event_503_command_5902:
    event_test_flag_range 195, 0, 8
event_503_command_5905:
    event_increment_flag 195
