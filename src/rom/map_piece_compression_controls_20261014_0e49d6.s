.setcpu "65816"
.segment "CODE"
.org $49D6
map_control_0e49d6:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
