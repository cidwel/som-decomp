; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $22BF
.include "src/rom/event_command_macros.inc"
event_0F4_command_22BF:
    event_call 252
event_0F4_command_22C1:
    event_world_transition 41
event_0F4_command_22C3:
    event_call 247
event_0F4_command_22C5:
    event_jump 1806
event_0F4_command_22C7:
    event_end 
event_0F5_command_22C8:
    event_object_command_37 50
