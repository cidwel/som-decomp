; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $65DD
.include "src/rom/event_command_macros.inc"
event_1B0_command_65DD:
    event_jump 433
event_1B0_command_65DF:
    event_jump 434
event_1B0_command_65E1:
    event_jump 433
event_1B0_command_65E3:
    event_end 
