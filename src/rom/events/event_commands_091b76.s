; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1B76
.include "src/rom/event_command_macros.inc"
event_0CF_command_1B76:
    event_jump 255
event_0CF_command_1B78:
    event_jump 239
event_0CF_command_1B7A:
    event_jump 240
event_0CF_command_1B7C:
    event_end 
event_0D0_command_1B7D:
    event_set_flag 15, 0
event_0D0_command_1B80:
    event_call 1032
