.setcpu "65816"
.segment "CODE"
.org $DE37
map_control_0dde37:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
