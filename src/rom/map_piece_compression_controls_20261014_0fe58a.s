.setcpu "65816"
.segment "CODE"
.org $E58A
map_control_0fe58a:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
