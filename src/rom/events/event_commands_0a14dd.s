; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $14DD
.include "src/rom/event_command_macros.inc"
event_42D_command_14DD:
    event_actor_animation 3, 142
event_42D_command_14E0:
    event_wait_idle 
event_42D_command_14E1:
    event_screen 2
event_42D_command_14E3:
    event_wait 0
