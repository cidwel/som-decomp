.setcpu "65816"
.segment "CODE"
.org $1FDD
map_control_0d1fdd:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
