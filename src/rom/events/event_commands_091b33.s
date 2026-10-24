; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1B33
.include "src/rom/event_command_macros.inc"
event_0CE_command_1B33:
    event_jump 255
event_0CE_command_1B35:
    event_jump 253
event_0CE_command_1B37:
    event_jump 254
event_0CE_command_1B39:
    event_end 
event_0CF_command_1B3A:
    event_set_flag 15, 0
event_0CF_command_1B3D:
    event_call 1032
