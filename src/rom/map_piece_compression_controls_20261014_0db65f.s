.setcpu "65816"
.segment "CODE"
.org $B65F
map_control_0db65f:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
