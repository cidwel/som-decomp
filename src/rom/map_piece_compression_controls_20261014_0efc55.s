.setcpu "65816"
.segment "CODE"
.org $FC55
map_control_0efc55:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
