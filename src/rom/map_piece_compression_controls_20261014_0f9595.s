.setcpu "65816"
.segment "CODE"
.org $9595
map_control_0f9595:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
