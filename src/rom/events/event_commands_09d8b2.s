; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D8B2
.include "src/rom/event_command_macros.inc"
event_37D_command_D8B2:
    event_jump 1535
event_37D_command_D8B4:
    event_end 
