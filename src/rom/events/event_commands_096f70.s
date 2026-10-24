; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F70
.include "src/rom/event_command_macros.inc"
event_1BE_command_6F70:
    event_actor_animation 0, 139
event_1BE_command_6F73:
    event_wait_idle 
event_1BE_command_6F74:
    event_screen 4
event_1BE_command_6F76:
    event_set_flag 96, 4
event_1BE_command_6F79:
    event_increment_flag 255
event_1BE_command_6F7B:
    event_increment_flag 20
event_1BE_command_6F7D:
    event_change_map 81
