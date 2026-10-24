; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $62F2
.include "src/rom/event_command_macros.inc"
event_550_command_62F2:
    event_jump 1535
event_550_command_62F4:
    event_end 
event_551_command_62F5:
    event_test_flag_range 45, 3, 15
event_551_command_62F8:
    event_jump 0
event_551_command_62FA:
    event_call 1948
event_551_command_62FC:
    event_call 1354
event_551_command_62FE:
    event_end 
event_552_command_62FF:
    event_jump 1796
event_552_command_6301:
    event_end 
event_553_command_6302:
    event_call 1284
event_553_command_6304:
    event_increment_flag 45
event_553_command_6306:
    event_jump 1607
event_553_command_6308:
    event_end 
event_554_command_6309:
    event_jump 1607
event_554_command_630B:
    event_end 
