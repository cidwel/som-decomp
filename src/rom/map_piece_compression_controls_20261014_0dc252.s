.setcpu "65816"
.segment "CODE"
.org $C252
map_control_0dc252:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
