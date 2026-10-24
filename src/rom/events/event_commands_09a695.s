; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A695
.include "src/rom/event_command_macros.inc"
event_276_command_A695:
    event_jump 1535
event_276_command_A697:
    event_end 
event_277_command_A698:
    event_actor_walk 4, 2, 0
event_277_command_A69B:
    event_wait_idle 
