.setcpu "65816"
.segment "CODE"
.org $C62D
map_control_0dc62d:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
