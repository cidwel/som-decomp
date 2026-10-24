; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DC76
.include "src/rom/event_command_macros.inc"
event_38F_command_DC76:
    event_jump 1535
event_38F_command_DC78:
    event_end 
