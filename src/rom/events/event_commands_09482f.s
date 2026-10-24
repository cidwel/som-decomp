; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $482F
.include "src/rom/event_command_macros.inc"
event_14D_command_482F:
    event_jump 1535
event_14D_command_4831:
    event_end 
