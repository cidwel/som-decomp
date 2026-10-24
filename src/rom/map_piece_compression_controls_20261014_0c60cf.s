.setcpu "65816"
.segment "CODE"
.org $60CF
map_control_0c60cf:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
