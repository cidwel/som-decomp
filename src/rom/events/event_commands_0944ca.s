; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44CA
.include "src/rom/event_command_macros.inc"
event_141_command_44CA:
    event_jump 1535
event_141_command_44CC:
    event_end 
event_142_command_44CD:
    event_test_flag_range 18, 0, 8
event_142_command_44D0:
    event_jump 334
