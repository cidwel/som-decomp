; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3170
.include "src/rom/event_command_macros.inc"
event_10C_command_3170:
    event_screen 4
event_10C_command_3172:
    event_screen_word 6, 0
event_10C_command_3176:
    event_wait_idle 
event_10C_command_3177:
    event_change_map 141
event_10C_command_3179:
    event_toggle_visibility_05 
event_10C_command_317A:
    event_increment_flag 255
