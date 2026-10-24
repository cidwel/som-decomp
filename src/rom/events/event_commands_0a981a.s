; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $981A
.include "src/rom/event_command_macros.inc"
event_7FD_command_981A:
    event_call 1051
event_7FD_command_981C:
    event_decrement_flag 255
event_7FD_command_981E:
    event_end 
event_7FE_command_981F:
    event_call 1991
event_7FE_command_9821:
    event_screen_word 6, 65535
event_7FE_command_9825:
    event_wait 32
event_7FE_command_9827:
    event_change_map 12
