.setcpu "65816"
.segment "CODE"
.org $7617
map_control_0e7617:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
