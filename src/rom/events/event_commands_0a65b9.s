; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $65B9
.include "src/rom/event_command_macros.inc"
event_558_command_65B9:
    event_screen_word 6, 17407
