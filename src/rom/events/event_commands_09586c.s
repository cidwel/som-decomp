; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $586C
.include "src/rom/event_command_macros.inc"
event_182_command_586C:
    event_jump 1535
event_182_command_586E:
    event_end 
event_183_command_586F:
    event_test_flag_range 18, 9, 15
event_183_command_5872:
    event_jump 407
