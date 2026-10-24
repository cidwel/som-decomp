; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0F32
.include "src/rom/event_command_macros.inc"
event_032_command_0F32:
    event_jump 1535
event_032_command_0F34:
    event_end 
event_033_command_0F35:
    event_end 
event_034_command_0F36:
    event_end 
event_035_command_0F37:
    event_end 
event_036_command_0F38:
    event_end 
event_037_command_0F39:
    event_end 
event_038_command_0F3A:
    event_increment_flag 24
event_038_command_0F3C:
    event_call 1951
event_038_command_0F3E:
    event_redraw_pieces 
event_038_command_0F3F:
    event_refresh_objects 
event_038_command_0F40:
    event_end 
event_039_command_0F41:
    event_end 
event_03A_command_0F42:
    event_end 
event_03B_command_0F43:
    event_end 
event_03C_command_0F44:
    event_end 
event_03D_command_0F45:
    event_end 
event_03E_command_0F46:
    event_end 
event_03F_command_0F47:
    event_set_flag 19, 3
event_03F_command_0F4A:
    event_return 
event_03F_command_0F4B:
    event_end 
