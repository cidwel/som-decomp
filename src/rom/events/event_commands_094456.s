; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4456
.include "src/rom/event_command_macros.inc"
event_13F_command_4456:
    event_jump 1535
event_13F_command_4458:
    event_end 
