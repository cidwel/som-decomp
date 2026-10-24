; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C762
.include "src/rom/event_command_macros.inc"
event_2E8_command_C762:
    event_jump 1535
event_2E8_command_C764:
    event_end 
