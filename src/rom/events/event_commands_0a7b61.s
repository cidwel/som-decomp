; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7B61
.include "src/rom/event_command_macros.inc"
event_5F8_command_7B61:
    event_actor_walk 4, 1, 0
event_5F8_command_7B64:
    event_wait_idle 
event_5F8_command_7B65:
    event_wait 32
