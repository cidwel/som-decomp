.setcpu "65816"
.segment "CODE"
.org $616E
map_control_0c616e:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
