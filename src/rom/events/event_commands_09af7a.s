; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AF7A
.include "src/rom/event_command_macros.inc"
event_295_command_AF7A:
    event_call 665
event_295_command_AF7C:
    event_increment_flag 40
event_295_command_AF7E:
    event_jump 663
event_295_command_AF80:
    event_end 
