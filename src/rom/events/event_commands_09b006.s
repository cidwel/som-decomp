; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B006
.include "src/rom/event_command_macros.inc"
event_299_command_B006:
    event_return 
event_299_command_B007:
    event_end 
event_29A_command_B008:
    event_test_flag_range 40, 6, 6
event_29A_command_B00B:
    event_jump 667
