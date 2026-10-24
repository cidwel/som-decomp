; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4359
.include "src/rom/event_command_macros.inc"
event_4E8_command_4359:
    event_actor_walk 5, 3, 0
event_4E8_command_435C:
    event_wait_idle 
