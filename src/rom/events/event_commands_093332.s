; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3332
.include "src/rom/event_command_macros.inc"
event_112_command_3332:
    event_audio_request 1, 20, 0, 255
event_112_command_3337:
    event_set_flag 16, 7
event_112_command_333A:
    event_change_map 142
