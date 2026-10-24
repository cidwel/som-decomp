; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1C16
.include "src/rom/event_command_macros.inc"
event_0D1_command_1C16:
    event_jump 255
event_0D1_command_1C18:
    event_jump 253
event_0D1_command_1C1A:
    event_jump 205
event_0D1_command_1C1C:
    event_end 
