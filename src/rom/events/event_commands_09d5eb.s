; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D5EB
.include "src/rom/event_command_macros.inc"
event_36F_command_D5EB:
    event_actor_walk 5, 2, 0
event_36F_command_D5EE:
    event_wait_idle 
