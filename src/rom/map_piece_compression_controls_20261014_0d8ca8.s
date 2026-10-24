.setcpu "65816"
.segment "CODE"
.org $8CA8
map_control_0d8ca8:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
