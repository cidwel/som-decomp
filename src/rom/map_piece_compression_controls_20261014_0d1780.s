.setcpu "65816"
.segment "CODE"
.org $1780
map_control_0d1780:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
