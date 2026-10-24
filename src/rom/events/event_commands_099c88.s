; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9C88
.include "src/rom/event_command_macros.inc"
event_236_command_9C88:
    event_increment_flag 24
event_236_command_9C8A:
    event_change_map 331
event_236_command_9C8C:
    event_jump 1796
event_236_command_9C8E:
    event_end 
event_237_command_9C8F:
    event_increment_flag 24
event_237_command_9C91:
    event_call 1282
event_237_command_9C93:
    event_change_map 222
event_237_command_9C95:
    event_call 2002
event_237_command_9C97:
    event_increment_flag 168
event_237_command_9C99:
    event_end 
event_238_command_9C9A:
    event_set_flag 97, 4
event_238_command_9C9D:
    event_test_flag_range 24, 0, 5
event_238_command_9CA0:
    event_jump 1834
event_238_command_9CA2:
    event_jump 1821
event_238_command_9CA4:
    event_end 
event_239_command_9CA5:
    event_call 849
event_239_command_9CA7:
    event_test_flag_range 24, 2, 15
event_239_command_9CAA:
    event_jump 0
event_239_command_9CAC:
    event_test_flag_range 153, 1, 1
event_239_command_9CAF:
    event_jump 56
event_239_command_9CB1:
    event_end 
event_23A_command_9CB2:
    event_test_flag_range 17, 13, 15
event_23A_command_9CB5:
    event_jump 0
