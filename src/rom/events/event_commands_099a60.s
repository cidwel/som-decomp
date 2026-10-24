; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9A60
.include "src/rom/event_command_macros.inc"
event_22E_command_9A60:
    event_screen_word 6, 17407
event_22E_command_9A64:
    event_wait 8
event_22E_command_9A66:
    event_screen 7
