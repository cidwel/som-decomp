; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0FAF
.include "src/rom/event_command_macros.inc"
event_040_command_0FAF:
    event_test_flag_range 192, 0, 0
event_040_command_0FB2:
    event_increment_flag 192
event_040_command_0FB4:
    event_set_flag 18, 5
event_040_command_0FB7:
    event_test_flag_range 19, 0, 2
event_040_command_0FBA:
    event_jump 63
event_040_command_0FBC:
    event_return 
event_040_command_0FBD:
    event_end 
