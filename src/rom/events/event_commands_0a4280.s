; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4280
.include "src/rom/event_command_macros.inc"
event_4E8_command_4280:
    event_wait 4
event_4E8_command_4282:
    event_toggle_visibility_04 
event_4E8_command_4283:
    event_wait 16
