; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D479
.include "src/rom/event_command_macros.inc"
event_36D_command_D479:
    event_screen 0
event_36D_command_D47B:
    event_wait 3
event_36D_command_D47D:
    event_screen 1
event_36D_command_D47F:
    event_call 1924
