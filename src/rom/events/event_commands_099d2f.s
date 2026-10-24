; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9D2F
.include "src/rom/event_command_macros.inc"
event_23A_command_9D2F:
    event_jump 1535
event_23A_command_9D31:
    event_end 
event_23B_command_9D32:
    event_test_flag_range 24, 3, 15
event_23B_command_9D35:
    event_jump 0
