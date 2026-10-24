; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E50
.include "src/rom/event_command_macros.inc"
event_0E0_command_1E50:
    event_jump 255
event_0E0_command_1E52:
    event_jump 234
event_0E0_command_1E54:
    event_jump 235
event_0E0_command_1E56:
    event_end 
event_0E1_command_1E57:
    event_set_flag 15, 0
event_0E1_command_1E5A:
    event_call 1032
