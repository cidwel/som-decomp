.setcpu "65816"
.segment "CODE"
.org $08A6
map_control_0d08a6:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
