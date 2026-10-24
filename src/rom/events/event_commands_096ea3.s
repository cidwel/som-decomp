; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6EA3
.include "src/rom/event_command_macros.inc"
event_1B9_command_6EA3:
    event_end 
event_1B9_command_6EA4:
    event_end 
event_1B9_command_6EA5:
    event_jump 469
event_1B9_command_6EA7:
    event_jump 470
event_1B9_command_6EA9:
    event_end 
event_1BA_command_6EAA:
    event_set_flag 253, 1
event_1BA_command_6EAD:
    event_set_flag 254, 14
event_1BA_command_6EB0:
    event_call 1998
event_1BA_command_6EB2:
    event_test_flag_range 17, 11, 11
event_1BA_command_6EB5:
    event_increment_flag 17
event_1BA_command_6EB7:
    event_test_flag_range 14, 1, 15
event_1BA_command_6EBA:
    event_jump 1780
event_1BA_command_6EBC:
    event_test_flag_range 13, 1, 1
event_1BA_command_6EBF:
    event_jump 445
event_1BA_command_6EC1:
    event_jump 1780
event_1BA_command_6EC3:
    event_end 
event_1BB_command_6EC4:
    event_set_flag 97, 1
event_1BB_command_6EC7:
    event_end 
event_1BC_command_6EC8:
    event_set_flag 97, 2
event_1BC_command_6ECB:
    event_jump 1806
event_1BC_command_6ECD:
    event_end 
event_1BD_command_6ECE:
    event_test_flag_range 4, 2, 15
event_1BD_command_6ED1:
    event_jump 1780
event_1BD_command_6ED3:
    event_test_actor 1
event_1BD_command_6ED5:
    event_jump 510
event_1BD_command_6ED7:
    event_freeze 
