; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82FB
.include "src/rom/event_command_macros.inc"
event_5F8_command_82FB:
    event_decrement_flag 248
