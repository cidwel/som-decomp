; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $429C
.include "src/rom/event_command_macros.inc"
event_13C_command_429C:
    event_jump 1535
event_13C_command_429E:
    event_end 
event_13D_command_429F:
    event_test_flag_range 144, 0, 1
event_13D_command_42A2:
    event_jump 318
