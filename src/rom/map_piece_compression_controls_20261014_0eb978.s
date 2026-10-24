.setcpu "65816"
.segment "CODE"
.org $B978
map_control_0eb978:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
