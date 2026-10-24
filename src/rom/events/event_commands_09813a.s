; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $813A
.include "src/rom/event_command_macros.inc"
event_1DE_command_813A:
    event_jump 479
event_1DE_command_813C:
    event_end 
event_1DF_command_813D:
    event_wait 0
