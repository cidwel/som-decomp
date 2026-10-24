; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AC2E
.include "src/rom/event_command_macros.inc"
event_28D_command_AC2E:
    event_jump 1535
event_28D_command_AC30:
    event_end 
