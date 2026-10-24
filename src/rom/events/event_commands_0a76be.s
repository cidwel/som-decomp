; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $76BE
.include "src/rom/event_command_macros.inc"
event_59B_command_76BE:
    event_actor_walk 5, 1, 0
event_59B_command_76C1:
    event_wait_idle 
