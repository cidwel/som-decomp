; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4EDF
.include "src/rom/event_command_macros.inc"
event_4FD_command_4EDF:
    event_actor_animation 1, 178
event_4FD_command_4EE2:
    event_actor_animation 2, 178
event_4FD_command_4EE5:
    event_wait_idle 
event_4FD_command_4EE6:
    event_increment_flag 247
event_4FD_command_4EE8:
    event_wait 8
event_4FD_command_4EEA:
    event_increment_flag 247
event_4FD_command_4EEC:
    event_wait 8
event_4FD_command_4EEE:
    event_increment_flag 247
event_4FD_command_4EF0:
    event_wait 8
event_4FD_command_4EF2:
    event_increment_flag 247
event_4FD_command_4EF4:
    event_wait 8
event_4FD_command_4EF6:
    event_set_flag 247, 6
event_4FD_command_4EF9:
    event_wait 8
event_4FD_command_4EFB:
    event_set_flag 247, 8
event_4FD_command_4EFE:
    event_wait 8
