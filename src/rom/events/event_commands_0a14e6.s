; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $14E6
.include "src/rom/event_command_macros.inc"
event_42D_command_14E6:
    event_call 1150
event_42D_command_14E8:
    event_actor_walk 1, 2, 0
event_42D_command_14EB:
    event_actor_walk 2, 3, 0
event_42D_command_14EE:
    event_wait_idle 
