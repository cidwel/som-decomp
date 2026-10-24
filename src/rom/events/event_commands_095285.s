; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5285
.include "src/rom/event_command_macros.inc"
event_16F_command_5285:
    event_jump 1535
event_16F_command_5287:
    event_end 
