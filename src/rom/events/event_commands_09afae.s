; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AFAE
.include "src/rom/event_command_macros.inc"
event_296_command_AFAE:
    event_set_flag 14, 1
event_296_command_AFB1:
    event_refresh_objects 
event_296_command_AFB2:
    event_clone_actor 2
event_296_command_AFB4:
    event_increment_flag 40
event_296_command_AFB6:
    event_end 
