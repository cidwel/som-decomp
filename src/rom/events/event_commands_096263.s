; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6263
.include "src/rom/event_command_macros.inc"
event_19F_command_6263:
    event_jump 1535
event_19F_command_6265:
    event_end 
event_1A0_command_6266:
    event_test_flag_range 18, 9, 15
event_1A0_command_6269:
    event_jump 421
