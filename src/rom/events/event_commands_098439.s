; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8439
.include "src/rom/event_command_macros.inc"
event_1E7_command_8439:
    event_actor_walk 4, 1, 0
event_1E7_command_843C:
    event_wait_idle 
