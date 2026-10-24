.setcpu "65816"
.segment "CODE"
.org $6DC6
map_control_0d6dc6:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
