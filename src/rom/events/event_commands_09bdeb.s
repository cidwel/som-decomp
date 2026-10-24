; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BDEB
.include "src/rom/event_command_macros.inc"
event_2C9_command_BDEB:
    event_jump 1535
event_2C9_command_BDED:
    event_end 
event_2CA_command_BDEE:
    event_call 1287
event_2CA_command_BDF0:
    event_set_flag 44, 3
event_2CA_command_BDF3:
    event_redraw_pieces 
event_2CA_command_BDF4:
    event_test_flag_range 38, 0, 5
event_2CA_command_BDF7:
    event_jump 1821
event_2CA_command_BDF9:
    event_jump 1821
event_2CA_command_BDFB:
    event_end 
event_2CB_command_BDFC:
    event_end 
