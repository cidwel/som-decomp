.setcpu "65816"
.segment "CODE"
.org $05A1
map_control_0e05a1:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
