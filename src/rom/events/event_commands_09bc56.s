; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BC56
.include "src/rom/event_command_macros.inc"
event_2BF_command_BC56:
    event_actor_walk 128, 3, 8
event_2BF_command_BC59:
    event_wait_idle 
event_2BF_command_BC5A:
    event_jump 690
event_2BF_command_BC5C:
    event_end 
