; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8DF9
.include "src/rom/event_command_macros.inc"
event_66E_command_8DF9:
    event_decrement_flag 248
event_66E_command_8DFB:
    event_end 
event_66F_command_8DFC:
    event_call 1864
event_66F_command_8DFE:
    event_screen_word 6, 65535
event_66F_command_8E02:
    event_wait 32
event_66F_command_8E04:
    event_call 1991
event_66F_command_8E06:
    event_change_map 512
event_66F_command_8E08:
    event_increment_flag 248
