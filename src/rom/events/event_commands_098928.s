; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8928
.include "src/rom/event_command_macros.inc"
event_1EE_command_8928:
    event_jump 0
event_1EE_command_892A:
    event_jump 498
event_1EE_command_892C:
    event_jump 0
event_1EE_command_892E:
    event_end 
event_1EF_command_892F:
    event_call 1948
event_1EF_command_8931:
    event_increment_flag 94
event_1EF_command_8933:
    event_redraw_pieces 
event_1EF_command_8934:
    event_end 
event_1F0_command_8935:
    event_audio_request 2, 29, 15, 136
event_1F0_command_893A:
    event_increment_flag 83
event_1F0_command_893C:
    event_redraw_pieces 
event_1F0_command_893D:
    event_return 
event_1F0_command_893E:
    event_end 
event_1F1_command_893F:
    event_end 
event_1F2_command_8940:
    event_increment_flag 23
event_1F2_command_8942:
    event_call 1940
event_1F2_command_8944:
    event_change_map 175
event_1F2_command_8946:
    event_jump 1559
event_1F2_command_8948:
    event_end 
event_1F3_command_8949:
    event_end 
