; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $138D
.include "src/rom/event_command_macros.inc"
event_081_command_138D:
    event_end 
event_081_command_138E:
    event_end 
event_081_command_138F:
    event_jump 130
event_081_command_1391:
    event_jump 131
event_081_command_1393:
    event_end 
event_082_command_1394:
    event_actor_walk 0, 0, 8
event_082_command_1397:
    event_wait_idle 
event_082_command_1398:
    event_screen 8
