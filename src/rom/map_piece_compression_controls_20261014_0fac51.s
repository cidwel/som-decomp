.setcpu "65816"
.segment "CODE"
.org $AC51
map_control_0fac51:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
