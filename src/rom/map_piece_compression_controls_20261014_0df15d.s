.setcpu "65816"
.segment "CODE"
.org $F15D
map_control_0df15d:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $23 ; distance low bit/count
