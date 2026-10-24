; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC30
.include "src/rom/event_command_macros.inc"
event_3DA_command_EC30:
    event_test_flag_range 63, 4, 4
event_3DA_command_EC33:
    event_jump 0
event_3DA_command_EC35:
    event_call 1948
event_3DA_command_EC37:
    event_increment_flag 63
event_3DA_command_EC39:
    event_redraw_pieces 
event_3DA_command_EC3A:
    event_call 1948
event_3DA_command_EC3C:
    event_increment_flag 63
event_3DA_command_EC3E:
    event_redraw_pieces 
event_3DA_command_EC3F:
    event_call 1948
event_3DA_command_EC41:
    event_increment_flag 63
event_3DA_command_EC43:
    event_redraw_pieces 
event_3DA_command_EC44:
    event_end 
event_3DB_command_EC45:
    event_test_flag_range 63, 6, 15
event_3DB_command_EC48:
    event_jump 0
event_3DB_command_EC4A:
    event_call 1152
event_3DB_command_EC4C:
    event_audio_request 2, 135, 15, 136
event_3DB_command_EC51:
    event_increment_flag 248
