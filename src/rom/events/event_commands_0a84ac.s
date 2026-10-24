; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $84AC
.include "src/rom/event_command_macros.inc"
event_5F8_command_84AC:
    event_actor_walk 1, 1, 4
event_5F8_command_84AF:
    event_wait_idle 
event_5F8_command_84B0:
    event_wait 0
