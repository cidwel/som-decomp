.setcpu "65816"
.segment "CODE"
.org $1FF5
map_control_0d1ff5:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
