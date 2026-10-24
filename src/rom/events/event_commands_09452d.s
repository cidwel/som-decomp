; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $452D
.include "src/rom/event_command_macros.inc"
event_143_command_452D:
    event_jump 1535
event_143_command_452F:
    event_end 
event_144_command_4530:
    event_test_flag_range 18, 0, 8
event_144_command_4533:
    event_jump 350
