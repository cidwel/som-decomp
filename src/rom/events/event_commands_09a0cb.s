; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A0CB
.include "src/rom/event_command_macros.inc"
event_253_command_A0CB:
    event_jump 599
event_253_command_A0CD:
    event_party_command 6
event_253_command_A0CF:
    event_jump 599
event_253_command_A0D1:
    event_end 
event_254_command_A0D2:
    event_test_flag_range 33, 13, 13
event_254_command_A0D5:
    event_jump 597
event_254_command_A0D7:
    event_test_flag_range 33, 13, 13
event_254_command_A0DA:
    event_jump 598
event_254_command_A0DC:
    event_change_map 48
event_254_command_A0DE:
    event_end 
event_255_command_A0DF:
    event_change_map 64
event_255_command_A0E1:
    event_jump 1796
event_255_command_A0E3:
    event_end 
event_256_command_A0E4:
    event_change_map 64
event_256_command_A0E6:
    event_jump 1796
event_256_command_A0E8:
    event_end 
