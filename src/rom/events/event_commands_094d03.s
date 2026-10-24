; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D03
.include "src/rom/event_command_macros.inc"
event_167_command_4D03:
    event_actor_walk 128, 0, 63
event_167_command_4D06:
    event_wait_idle 
event_167_command_4D07:
    event_increment_flag 18
event_167_command_4D09:
    event_refresh_objects 
