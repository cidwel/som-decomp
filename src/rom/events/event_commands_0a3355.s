; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3355
.include "src/rom/event_command_macros.inc"
event_4E2_command_3355:
    event_actor_walk 128, 1, 0
event_4E2_command_3358:
    event_wait_idle 
