; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0AFF
.include "src/rom/event_command_macros.inc"
event_023_command_0AFF:
    event_jump 1535
event_023_command_0B01:
    event_end 
