; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B8C6
.include "src/rom/event_command_macros.inc"
event_2B2_command_B8C6:
    event_screen_word 6, 30313
event_2B2_command_B8CA:
    event_wait 32
event_2B2_command_B8CC:
    event_increment_flag 41
event_2B2_command_B8CE:
    event_redraw_pieces 
event_2B2_command_B8CF:
    event_screen 7
event_2B2_command_B8D1:
    event_call 2014
