; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9144
.include "src/rom/event_command_macros.inc"
event_205_command_9144:
    event_actor_walk 5, 1, 16
event_205_command_9147:
    event_jump 514
event_205_command_9149:
    event_end 
event_206_command_914A:
    event_call 95
