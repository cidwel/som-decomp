.setcpu "65816"
.segment "CODE"
.org $1069
map_control_0f1069:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
