.setcpu "65816"
.segment "CODE"
.org $44C0
map_control_0c44c0:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
