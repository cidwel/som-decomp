; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9EB2
.include "src/rom/event_command_macros.inc"
event_24A_command_9EB2:
    event_test_flag_range 33, 0, 0
event_24A_command_9EB5:
    event_jump 600
event_24A_command_9EB7:
    event_test_flag_range 33, 1, 1
event_24A_command_9EBA:
    event_jump 536
event_24A_command_9EBC:
    event_jump 1535
event_24A_command_9EBE:
    event_end 
