; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E205
.include "src/rom/event_command_macros.inc"
event_3AA_command_E205:
    event_actor_walk 2, 2, 0
event_3AA_command_E208:
    event_wait_idle 
