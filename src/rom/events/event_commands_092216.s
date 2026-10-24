; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2216
.include "src/rom/event_command_macros.inc"
event_0F1_command_2216:
    event_call 252
event_0F1_command_2218:
    event_world_transition 43
event_0F1_command_221A:
    event_call 247
event_0F1_command_221C:
    event_jump 1555
event_0F1_command_221E:
    event_end 
