; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $58B9
.include "src/rom/event_command_macros.inc"
event_183_command_58B9:
    event_jump 1535
event_183_command_58BB:
    event_end 
event_184_command_58BC:
    event_test_flag_range 18, 9, 15
event_184_command_58BF:
    event_jump 412
