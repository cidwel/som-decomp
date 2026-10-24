; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $49EC
.include "src/rom/event_command_macros.inc"
event_156_command_49EC:
    event_jump 1535
event_156_command_49EE:
    event_end 
event_157_command_49EF:
    event_test_flag_range 13, 1, 1
event_157_command_49F2:
    event_jump 345
