.setcpu "65816"
.segment "CODE"
.org $57AC
map_control_0e57ac:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
