; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5EDD
.include "src/rom/event_command_macros.inc"
event_192_command_5EDD:
    event_set_flag 18, 3
event_192_command_5EE0:
    event_jump 1535
event_192_command_5EE2:
    event_end 
event_193_command_5EE3:
    event_actor_walk 6, 3, 0
event_193_command_5EE6:
    event_wait_idle 
