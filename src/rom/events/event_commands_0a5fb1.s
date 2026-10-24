; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FB1
.include "src/rom/event_command_macros.inc"
event_52F_command_5FB1:
    event_decrement_flag 248
