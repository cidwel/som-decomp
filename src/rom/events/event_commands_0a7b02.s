; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7B02
.include "src/rom/event_command_macros.inc"
event_5F8_command_7B02:
    event_actor_walk 4, 3, 0
event_5F8_command_7B05:
    event_wait_idle 
event_5F8_command_7B06:
    event_wait 32
