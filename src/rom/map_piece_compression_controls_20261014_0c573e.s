.setcpu "65816"
.segment "CODE"
.org $573E
map_control_0c573e:
    .byte $F2 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
