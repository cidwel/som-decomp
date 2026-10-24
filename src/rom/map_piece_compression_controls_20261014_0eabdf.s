.setcpu "65816"
.segment "CODE"
.org $ABDF
map_control_0eabdf:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
