.setcpu "65816"
.segment "CODE"
.org $38EB
map_control_0d38eb:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
