; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $687C
.include "src/rom/event_command_macros.inc"
event_1B3_command_687C:
    event_jump 433
event_1B3_command_687E:
    event_jump 434
event_1B3_command_6880:
    event_jump 433
event_1B3_command_6882:
    event_end 
