; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9ED1
.include "src/rom/event_command_macros.inc"
event_24B_command_9ED1:
    event_test_flag_range 32, 2, 15
event_24B_command_9ED4:
    event_jump 1535
event_24B_command_9ED6:
    event_set_flag 32, 2
