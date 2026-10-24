; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $562C
.include "src/rom/event_command_macros.inc"
event_17F_command_562C:
    event_jump 1535
event_17F_command_562E:
    event_end 
event_180_command_562F:
    event_actor_walk 4, 1, 0
event_180_command_5632:
    event_wait_idle 
