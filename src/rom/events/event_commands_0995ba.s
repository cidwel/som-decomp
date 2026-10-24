; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $95BA
.include "src/rom/event_command_macros.inc"
event_218_command_95BA:
    event_jump 1535
event_218_command_95BC:
    event_end 
event_219_command_95BD:
    event_increment_flag 33
event_219_command_95BF:
    event_redraw_pieces 
event_219_command_95C0:
    event_audio_request 2, 23, 15, 255
event_219_command_95C5:
    event_audio_request 2, 29, 15, 255
