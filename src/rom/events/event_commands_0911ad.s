; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $11AD
.include "src/rom/event_command_macros.inc"
event_062_command_11AD:
    event_jump 99
event_062_command_11AF:
    event_jump 100
event_062_command_11B1:
    event_jump 101
event_062_command_11B3:
    event_end 
event_063_command_11B4:
    event_call 95
