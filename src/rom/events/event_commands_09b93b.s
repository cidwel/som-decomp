; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B93B
.include "src/rom/event_command_macros.inc"
event_2B2_command_B93B:
    event_hero_command 72
event_2B2_command_B93D:
    event_jump 1567
event_2B2_command_B93F:
    event_end 
