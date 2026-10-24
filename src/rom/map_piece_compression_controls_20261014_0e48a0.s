.setcpu "65816"
.segment "CODE"
.org $48A0
map_control_0e48a0:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
