; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19E4
.include "src/rom/event_command_macros.inc"
event_4A2_command_19E4:
    event_decrement_flag 248
event_4A2_command_19E6:
    event_decrement_flag 255
event_4A2_command_19E8:
    event_call 2012
event_4A2_command_19EA:
    event_increment_flag 68
event_4A2_command_19EC:
    event_redraw_pieces 
event_4A2_command_19ED:
    event_end 
event_4A3_command_19EE:
    event_test_flag_range 68, 7, 15
event_4A3_command_19F1:
    event_jump 0
event_4A3_command_19F3:
    event_increment_flag 68
event_4A3_command_19F5:
    event_change_map 1014
event_4A3_command_19F7:
    event_call 1152
event_4A3_command_19F9:
    event_call 1988
event_4A3_command_19FB:
    event_increment_flag 255
