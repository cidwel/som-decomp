; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DC5F
.include "src/rom/event_command_macros.inc"
event_38E_command_DC5F:
    event_jump 1535
event_38E_command_DC61:
    event_end 
