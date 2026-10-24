; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4028
.include "src/rom/event_command_macros.inc"
event_139_command_4028:
    event_jump 1535
event_139_command_402A:
    event_end 
