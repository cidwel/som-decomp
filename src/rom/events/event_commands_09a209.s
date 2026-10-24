; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A209
.include "src/rom/event_command_macros.inc"
event_259_command_A209:
    event_jump 1535
event_259_command_A20B:
    event_end 
event_25A_command_A20C:
    event_call 850
event_25A_command_A20E:
    event_test_flag_range 154, 1, 1
event_25A_command_A211:
    event_jump 603
event_25A_command_A213:
    event_call 1945
event_25A_command_A215:
    event_end 
event_25B_command_A216:
    event_call 1940
event_25B_command_A218:
    event_set_flag 32, 4
event_25B_command_A21B:
    event_refresh_objects 
event_25B_command_A21C:
    event_redraw_pieces 
event_25B_command_A21D:
    event_end 
event_25C_command_A21E:
    event_end 
