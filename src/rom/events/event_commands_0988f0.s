; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $88F0
.include "src/rom/event_command_macros.inc"
event_1ED_command_88F0:
    event_end 
event_1EE_command_88F1:
    event_test_flag_range 216, 0, 1
event_1EE_command_88F4:
    event_jump 491
