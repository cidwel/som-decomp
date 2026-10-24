; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $329F
.include "src/rom/event_command_macros.inc"
event_10F_command_329F:
    event_jump 1535
event_10F_command_32A1:
    event_end 
event_110_command_32A2:
    event_test_flag_range 16, 10, 15
event_110_command_32A5:
    event_jump 280
