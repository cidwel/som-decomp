; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2684
.include "src/rom/event_command_macros.inc"
event_4C8_command_2684:
    event_actor_walk 4, 1, 0
event_4C8_command_2687:
    event_actor_walk 5, 1, 0
event_4C8_command_268A:
    event_wait_idle 
event_4C8_command_268B:
    event_wait 0
