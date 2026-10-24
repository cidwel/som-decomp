.setcpu "65816"
.segment "CODE"
.org $F97D
map_control_0ef97d:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
