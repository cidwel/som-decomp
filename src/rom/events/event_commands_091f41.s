; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F41
.include "src/rom/event_command_macros.inc"
event_0E3_command_1F41:
    event_jump 255
event_0E3_command_1F43:
    event_jump 231
event_0E3_command_1F45:
    event_jump 232
event_0E3_command_1F47:
    event_jump 233
event_0E3_command_1F49:
    event_end 
event_0E4_command_1F4A:
    event_end 
