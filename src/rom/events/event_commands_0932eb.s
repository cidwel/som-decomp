; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $32EB
.include "src/rom/event_command_macros.inc"
event_110_command_32EB:
    event_jump 1535
event_110_command_32ED:
    event_end 
