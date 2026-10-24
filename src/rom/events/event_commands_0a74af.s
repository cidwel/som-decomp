; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $74AF
.include "src/rom/event_command_macros.inc"
event_592_command_74AF:
    event_actor_walk 3, 3, 0
event_592_command_74B2:
    event_wait_idle 
