; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $42F8
.include "src/rom/event_command_macros.inc"
event_4E8_command_42F8:
    event_actor_walk 6, 0, 8
event_4E8_command_42FB:
    event_wait_idle 
event_4E8_command_42FC:
    event_actor_walk 6, 2, 0
event_4E8_command_42FF:
    event_wait_idle 
