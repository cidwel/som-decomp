; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $674D
.include "src/rom/event_command_macros.inc"
event_1B2_command_674D:
    event_screen_word 6, 17407
event_1B2_command_6751:
    event_wait 8
event_1B2_command_6753:
    event_screen 7
