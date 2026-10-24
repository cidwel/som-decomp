; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $592F
.include "src/rom/event_command_macros.inc"
event_504_command_592F:
    event_jump 1289
event_504_command_5931:
    event_end 
event_505_command_5932:
    event_test_flag_range 189, 9, 15
event_505_command_5935:
    event_jump 1288
event_505_command_5937:
    event_increment_flag 189
event_505_command_5939:
    event_test_flag_range 197, 0, 8
event_505_command_593C:
    event_increment_flag 197
