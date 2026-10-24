; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B763
.include "src/rom/event_command_macros.inc"
event_2AF_command_B763:
    event_jump 1535
event_2AF_command_B765:
    event_end 
event_2B0_command_B766:
    event_test_flag_range 41, 1, 1
event_2B0_command_B769:
    event_jump 690
event_2B0_command_B76B:
    event_test_flag_range 41, 2, 15
event_2B0_command_B76E:
    event_jump 691
event_2B0_command_B770:
    event_test_flag_range 147, 1, 2
event_2B0_command_B773:
    event_jump 689
event_2B0_command_B775:
    event_test_flag_range 38, 6, 6
event_2B0_command_B778:
    event_jump 686
