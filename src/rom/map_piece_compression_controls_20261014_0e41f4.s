.setcpu "65816"
.segment "CODE"
.org $41F4
map_control_0e41f4:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
