; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F5B
.include "src/rom/event_command_macros.inc"
event_582_command_6F5B:
    event_set_flag 170, 2
event_582_command_6F5E:
    event_set_actor_field 2, 202, 56
event_582_command_6F62:
    event_set_actor_field 3, 202, 7
event_582_command_6F66:
    event_return 
event_582_command_6F67:
    event_end 
event_583_command_6F68:
    event_set_actor_field 2, 203, 56
event_583_command_6F6C:
    event_set_actor_field 3, 203, 7
