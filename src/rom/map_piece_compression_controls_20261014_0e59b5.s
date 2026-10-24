.setcpu "65816"
.segment "CODE"
.org $59B5
map_control_0e59b5:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
