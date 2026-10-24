.setcpu "65816"
.segment "CODE"
.org $89C4
map_control_0d89c4:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
