; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A09D
.include "src/rom/event_command_macros.inc"
event_253_command_A09D:
    event_call 1051
event_253_command_A09F:
    event_restore_hero 132
