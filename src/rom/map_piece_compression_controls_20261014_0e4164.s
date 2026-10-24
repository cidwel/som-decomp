.setcpu "65816"
.segment "CODE"
.org $4164
map_control_0e4164:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
