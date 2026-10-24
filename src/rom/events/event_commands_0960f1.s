; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $60F1
.include "src/rom/event_command_macros.inc"
event_198_command_60F1:
    event_actor_walk 128, 0, 0
event_198_command_60F4:
    event_wait_idle 
event_198_command_60F5:
    event_end 
