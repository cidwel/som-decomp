; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9F74
.include "src/rom/event_command_macros.inc"
event_24C_command_9F74:
    event_set_flag 32, 3
event_24C_command_9F77:
    event_change_map 496
event_24C_command_9F79:
    event_jump 1809
event_24C_command_9F7B:
    event_end 
event_24D_command_9F7C:
    event_test_flag_range 33, 1, 1
event_24D_command_9F7F:
    event_jump 537
event_24D_command_9F81:
    event_end 
event_24E_command_9F82:
    event_change_map 498
event_24E_command_9F84:
    event_jump 1561
event_24E_command_9F86:
    event_end 
