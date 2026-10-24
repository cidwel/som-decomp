; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1EFB
.include "src/rom/event_command_macros.inc"
event_0E2_command_1EFB:
    event_jump 255
event_0E2_command_1EFD:
    event_jump 255
event_0E2_command_1EFF:
    event_jump 230
event_0E2_command_1F01:
    event_end 
