; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5949
.include "src/rom/event_command_macros.inc"
event_505_command_5949:
    event_jump 1289
event_505_command_594B:
    event_end 
event_506_command_594C:
    event_test_flag_range 190, 9, 15
event_506_command_594F:
    event_jump 1288
event_506_command_5951:
    event_increment_flag 190
event_506_command_5953:
    event_test_flag_range 198, 0, 8
event_506_command_5956:
    event_increment_flag 198
