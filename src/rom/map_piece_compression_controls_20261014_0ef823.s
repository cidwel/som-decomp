.setcpu "65816"
.segment "CODE"
.org $F823
map_control_0ef823:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
