; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $42E4
.include "src/rom/event_command_macros.inc"
event_13D_command_42E4:
    event_jump 1535
event_13D_command_42E6:
    event_end 
event_13E_command_42E7:
    event_test_flag_range 30, 7, 15
event_13E_command_42EA:
    event_jump 308
