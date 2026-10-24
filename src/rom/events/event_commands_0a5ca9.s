; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5CA9
.include "src/rom/event_command_macros.inc"
event_51D_command_5CA9:
    event_increment_flag 52
event_51D_command_5CAB:
    event_change_map 836
event_51D_command_5CAD:
    event_end 
event_51E_command_5CAE:
    event_test_flag_range 53, 0, 0
event_51E_command_5CB1:
    event_jump 1307
event_51E_command_5CB3:
    event_end 
event_51F_command_5CB4:
    event_test_flag_range 221, 2, 15
event_51F_command_5CB7:
    event_jump 0
event_51F_command_5CB9:
    event_call 1932
event_51F_command_5CBB:
    event_set_flag 221, 2
event_51F_command_5CBE:
    event_redraw_pieces 
event_51F_command_5CBF:
    event_end 
event_520_command_5CC0:
    event_test_flag_range 52, 1, 15
event_520_command_5CC3:
    event_jump 0
