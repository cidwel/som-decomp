.setcpu "65816"
.segment "CODE"
.org $99B8
map_control_0d99b8:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
