.setcpu "65816"
.segment "CODE"
.org $3100
map_control_0e3100:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
