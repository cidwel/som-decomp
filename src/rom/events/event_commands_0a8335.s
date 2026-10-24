; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8335
.include "src/rom/event_command_macros.inc"
event_5F8_command_8335:
    event_increment_flag 248
