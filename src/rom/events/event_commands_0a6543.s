; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6543
.include "src/rom/event_command_macros.inc"
event_558_command_6543:
    event_wait 8
event_558_command_6545:
    event_call 1927
event_558_command_6547:
    event_call 1040
