.setcpu "65816"
.segment "CODE"
.org $0852
map_control_0d0852:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
