.setcpu "65816"
.segment "CODE"
.org $99A7
map_control_0d99a7:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
