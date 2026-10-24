.setcpu "65816"
.segment "CODE"
.org $7BA8
map_control_0e7ba8:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
