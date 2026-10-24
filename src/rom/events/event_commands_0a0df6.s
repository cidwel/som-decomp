; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0DF6
.include "src/rom/event_command_macros.inc"
event_400_command_0DF6:
    event_screen_word 6, 65535
event_400_command_0DFA:
    event_wait 48
