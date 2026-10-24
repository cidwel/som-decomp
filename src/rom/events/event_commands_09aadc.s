; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AADC
.include "src/rom/event_command_macros.inc"
event_28B_command_AADC:
    event_actor_walk 4, 1, 0
event_28B_command_AADF:
    event_wait_idle 
