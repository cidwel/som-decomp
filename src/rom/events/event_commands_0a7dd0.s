; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7DD0
.include "src/rom/event_command_macros.inc"
event_5F8_command_7DD0:
    event_wait 32
event_5F8_command_7DD2:
    event_call 1848
event_5F8_command_7DD4:
    event_screen_word 5, 736
event_5F8_command_7DD8:
    event_wait 16
event_5F8_command_7DDA:
    event_call 1151
event_5F8_command_7DDC:
    event_call 83
event_5F8_command_7DDE:
    event_increment_flag 248
