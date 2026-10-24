.setcpu "65816"
.segment "CODE"
.org $9B47
map_control_0d9b47:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
