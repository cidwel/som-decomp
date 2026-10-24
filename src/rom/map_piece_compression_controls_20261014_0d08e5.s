.setcpu "65816"
.segment "CODE"
.org $08E5
map_control_0d08e5:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
