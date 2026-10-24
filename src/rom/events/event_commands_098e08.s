; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E08
.include "src/rom/event_command_macros.inc"
event_202_command_8E08:
    event_end 
event_202_command_8E09:
    event_end 
event_202_command_8E0A:
    event_jump 518
event_202_command_8E0C:
    event_jump 516
event_202_command_8E0E:
    event_end 
event_203_command_8E0F:
    event_test_flag_range 10, 2, 15
event_203_command_8E12:
    event_jump 517
event_203_command_8E14:
    event_increment_flag 10
