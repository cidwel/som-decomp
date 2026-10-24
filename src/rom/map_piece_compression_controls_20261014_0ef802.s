.setcpu "65816"
.segment "CODE"
.org $F802
map_control_0ef802:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
