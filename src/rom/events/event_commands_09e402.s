; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E402
.include "src/rom/event_command_macros.inc"
event_3AF_command_E402:
    event_jump 1535
event_3AF_command_E404:
    event_end 
