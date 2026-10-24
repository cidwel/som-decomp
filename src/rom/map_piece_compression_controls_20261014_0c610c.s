.setcpu "65816"
.segment "CODE"
.org $610C
map_control_0c610c:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
