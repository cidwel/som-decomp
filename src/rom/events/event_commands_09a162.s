; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A162
.include "src/rom/event_command_macros.inc"
event_258_command_A162:
    event_jump 536
event_258_command_A164:
    event_end 
event_259_command_A165:
    event_increment_flag 32
