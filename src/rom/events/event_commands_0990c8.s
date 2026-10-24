; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $90C8
.include "src/rom/event_command_macros.inc"
event_204_command_90C8:
    event_set_flag 10, 0
event_204_command_90CB:
    event_increment_flag 17
event_204_command_90CD:
    event_increment_flag 18
event_204_command_90CF:
    event_increment_flag 165
event_204_command_90D1:
    event_increment_flag 166
event_204_command_90D3:
    event_redraw_pieces 
event_204_command_90D4:
    event_jump 308
event_204_command_90D6:
    event_end 
event_205_command_90D7:
    event_actor_walk 5, 0, 16
