; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21C0
.include "src/rom/event_command_macros.inc"
event_0EF_command_21C0:
    event_call 252
event_0EF_command_21C2:
    event_world_transition 38
event_0EF_command_21C4:
    event_call 247
event_0EF_command_21C6:
    event_jump 1552
event_0EF_command_21C8:
    event_end 
event_0F0_command_21C9:
    event_object_command_37 50
