; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21F1
.include "src/rom/event_command_macros.inc"
event_0F0_command_21F1:
    event_call 252
event_0F0_command_21F3:
    event_world_transition 42
event_0F0_command_21F5:
    event_call 247
event_0F0_command_21F7:
    event_jump 1797
event_0F0_command_21F9:
    event_end 
event_0F1_command_21FA:
    event_object_command_37 50
