; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8439
.include "src/rom/event_command_macros.inc"
event_5F8_command_8439:
    event_actor_walk 1, 1, 0
event_5F8_command_843C:
    event_wait_idle 
