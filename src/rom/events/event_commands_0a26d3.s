; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $26D3
.include "src/rom/event_command_macros.inc"
event_4C8_command_26D3:
    event_call 1988
event_4C8_command_26D5:
    event_set_flag 71, 2
event_4C8_command_26D8:
    event_change_map 967
event_4C8_command_26DA:
    event_end 
event_4C9_command_26DB:
    event_test_flag_range 71, 0, 2
event_4C9_command_26DE:
    event_jump 1227
event_4C9_command_26E0:
    event_change_map 1022
event_4C9_command_26E2:
    event_jump 1576
event_4C9_command_26E4:
    event_end 
event_4CA_command_26E5:
    event_set_flag 71, 1
event_4CA_command_26E8:
    event_call 1285
event_4CA_command_26EA:
    event_call 2013
event_4CA_command_26EC:
    event_change_map 967
event_4CA_command_26EE:
    event_call 1152
