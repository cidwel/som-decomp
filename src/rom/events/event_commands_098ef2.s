; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8EF2
.include "src/rom/event_command_macros.inc"
event_203_command_8EF2:
    event_call 94
event_203_command_8EF4:
    event_test_flag_range 10, 2, 15
event_203_command_8EF7:
    event_jump 517
event_203_command_8EF9:
    event_jump 512
event_203_command_8EFB:
    event_end 
event_204_command_8EFC:
    event_call 94
