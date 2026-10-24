; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D15
.include "src/rom/event_command_macros.inc"
event_167_command_4D15:
    event_actor_walk 2, 0, 16
event_167_command_4D18:
    event_wait_idle 
event_167_command_4D19:
    event_wait 8
