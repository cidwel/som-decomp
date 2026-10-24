.setcpu "65816"
.segment "CODE"
.org $A3EE
map_control_0fa3ee:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
