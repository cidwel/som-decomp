; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7CC6
.include "src/rom/event_command_macros.inc"
event_1D7_command_7CC6:
    event_jump 479
event_1D7_command_7CC8:
    event_end 
event_1D8_command_7CC9:
    event_test_flag_range 22, 1, 15
event_1D8_command_7CCC:
    event_jump 484
event_1D8_command_7CCE:
    event_test_flag_range 13, 1, 15
event_1D8_command_7CD1:
    event_jump 484
event_1D8_command_7CD3:
    event_call 1939
event_1D8_command_7CD5:
    event_change_map 174
