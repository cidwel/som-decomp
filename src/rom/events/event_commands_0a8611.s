; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8611
.include "src/rom/event_command_macros.inc"
event_604_command_8611:
    event_call 1546
event_604_command_8613:
    event_jump 1535
event_604_command_8615:
    event_end 
