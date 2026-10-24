; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $832E
.include "src/rom/event_command_macros.inc"
event_5F8_command_832E:
    event_actor_walk 1, 0, 8
event_5F8_command_8331:
    event_wait_idle 
event_5F8_command_8332:
    event_wait 0
