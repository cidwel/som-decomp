.setcpu "65816"
.segment "CODE"
.org $49BD
map_control_0e49bd:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
