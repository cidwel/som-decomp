; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E33
.include "src/rom/event_command_macros.inc"
event_581_command_6E33:
    event_set_actor_field 2, 201, 56
event_581_command_6E37:
    event_set_actor_field 3, 201, 7
event_581_command_6E3B:
    event_increment_flag 169
event_581_command_6E3D:
    event_refresh_objects 
event_581_command_6E3E:
    event_decrement_flag 169
event_581_command_6E40:
    event_refresh_objects 
event_581_command_6E41:
    event_increment_flag 169
event_581_command_6E43:
    event_refresh_objects 
event_581_command_6E44:
    event_decrement_flag 169
event_581_command_6E46:
    event_refresh_objects 
event_581_command_6E47:
    event_increment_flag 169
event_581_command_6E49:
    event_refresh_objects 
event_581_command_6E4A:
    event_wait 16
