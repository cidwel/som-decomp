; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7AA7
.include "src/rom/event_command_macros.inc"
event_5F8_command_7AA7:
    event_actor_walk 4, 2, 0
event_5F8_command_7AAA:
    event_wait_idle 
event_5F8_command_7AAB:
    event_wait 64
