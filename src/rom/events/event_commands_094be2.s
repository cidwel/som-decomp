; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4BE2
.include "src/rom/event_command_macros.inc"
event_15D_command_4BE2:
    event_jump 1535
event_15D_command_4BE4:
    event_end 
