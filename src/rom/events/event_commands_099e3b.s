; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9E3B
.include "src/rom/event_command_macros.inc"
event_23F_command_9E3B:
    event_change_map 498
event_23F_command_9E3D:
    event_jump 1561
event_23F_command_9E3F:
    event_end 
event_240_command_9E40:
    event_change_map 479
event_240_command_9E42:
    event_set_flag 84, 0
event_240_command_9E45:
    event_end 
event_241_command_9E46:
    event_change_map 478
event_241_command_9E48:
    event_test_flag_range 84, 0, 0
event_241_command_9E4B:
    event_increment_flag 84
event_241_command_9E4D:
    event_end 
event_242_command_9E4E:
    event_change_map 508
event_242_command_9E50:
    event_set_flag 84, 0
event_242_command_9E53:
    event_end 
event_243_command_9E54:
    event_change_map 507
event_243_command_9E56:
    event_test_flag_range 84, 1, 1
event_243_command_9E59:
    event_increment_flag 84
event_243_command_9E5B:
    event_end 
event_244_command_9E5C:
    event_change_map 514
event_244_command_9E5E:
    event_set_flag 84, 0
event_244_command_9E61:
    event_end 
event_245_command_9E62:
    event_test_flag_range 84, 2, 2
event_245_command_9E65:
    event_increment_flag 84
event_245_command_9E67:
    event_test_flag_range 32, 0, 2
event_245_command_9E6A:
    event_change_map 513
event_245_command_9E6C:
    event_test_flag_range 32, 3, 15
event_245_command_9E6F:
    event_change_map 481
event_245_command_9E71:
    event_end 
event_246_command_9E72:
    event_set_flag 84, 0
event_246_command_9E75:
    event_test_flag_range 32, 0, 2
event_246_command_9E78:
    event_change_map 486
event_246_command_9E7A:
    event_test_flag_range 32, 3, 15
event_246_command_9E7D:
    event_change_map 480
event_246_command_9E7F:
    event_end 
event_247_command_9E80:
    event_change_map 487
event_247_command_9E82:
    event_test_flag_range 84, 3, 3
event_247_command_9E85:
    event_jump 589
event_247_command_9E87:
    event_end 
event_248_command_9E88:
    event_test_flag_range 32, 0, 1
event_248_command_9E8B:
    event_jump 575
event_248_command_9E8D:
    event_test_flag_range 32, 2, 2
event_248_command_9E90:
    event_jump 585
event_248_command_9E92:
    event_change_map 505
event_248_command_9E94:
    event_jump 1809
event_248_command_9E96:
    event_end 
event_249_command_9E97:
    event_change_map 497
event_249_command_9E99:
    event_jump 1806
event_249_command_9E9B:
    event_end 
