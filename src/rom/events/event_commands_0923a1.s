; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $23A1
.include "src/rom/event_command_macros.inc"
event_0FA_command_23A1:
    event_call 252
event_0FA_command_23A3:
    event_world_transition 32
event_0FA_command_23A5:
    event_call 247
event_0FA_command_23A7:
    event_jump 1806
event_0FA_command_23A9:
    event_end 
