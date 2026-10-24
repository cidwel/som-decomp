; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2759
.include "src/rom/event_command_macros.inc"
event_103_command_2759:
    event_screen_word 6, 17407
