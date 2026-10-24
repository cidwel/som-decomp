; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $65F7
.include "src/rom/event_command_macros.inc"
event_558_command_65F7:
    event_actor_walk 4, 1, 16
event_558_command_65FA:
    event_wait_idle 
event_558_command_65FB:
    event_increment_flag 45
event_558_command_65FD:
    event_set_flag 13, 1
event_558_command_6600:
    event_refresh_objects 
event_558_command_6601:
    event_clone_actor 1
event_558_command_6603:
    event_actor_animation_loop 2, 171
event_558_command_6606:
    event_set_actor_field 2, 144, 0
event_558_command_660A:
    event_set_actor_field 2, 145, 0
event_558_command_660E:
    event_restore_hero 2
event_558_command_6610:
    event_restore_hero 66
event_558_command_6612:
    event_native_command_35 
event_558_command_6613:
    event_call 1151
