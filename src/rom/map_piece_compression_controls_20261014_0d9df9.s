.setcpu "65816"
.segment "CODE"
.org $9DF9
map_control_0d9df9:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
