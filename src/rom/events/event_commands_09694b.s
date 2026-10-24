; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $694B
.include "src/rom/event_command_macros.inc"
event_1B5_command_694B:
    event_screen_word 6, 17407
event_1B5_command_694F:
    event_wait 8
event_1B5_command_6951:
    event_screen 7
