; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9165
.include "src/rom/event_command_macros.inc"
event_206_command_9165:
    event_increment_flag 10
event_206_command_9167:
    event_jump 515
event_206_command_9169:
    event_end 
event_207_command_916A:
    event_actor_walk 5, 0, 16
event_207_command_916D:
    event_wait 0
