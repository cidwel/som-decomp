; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $39EB
.include "src/rom/event_command_macros.inc"
event_4E4_command_39EB:
    event_set_flag 36, 7
event_4E4_command_39EE:
    event_screen_word 6, 0
event_4E4_command_39F2:
    event_call 1947
event_4E4_command_39F4:
    event_wait 32
event_4E4_command_39F6:
    event_call 1947
event_4E4_command_39F8:
    event_wait 32
event_4E4_command_39FA:
    event_change_map 462
event_4E4_command_39FC:
    event_actor_walk 0, 0, 32
event_4E4_command_39FF:
    event_wait_idle 
event_4E4_command_3A00:
    event_screen 8
event_4E4_command_3A02:
    event_call 1151
