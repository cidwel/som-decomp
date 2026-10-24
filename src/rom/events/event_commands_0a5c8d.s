; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5C8D
.include "src/rom/event_command_macros.inc"
event_51D_command_5C8D:
    event_screen_word 6, 65535
