; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3214
.include "src/rom/event_command_macros.inc"
event_4E2_command_3214:
    event_actor_walk 128, 0, 0
event_4E2_command_3217:
    event_wait_idle 
