.setcpu "65816"
.segment "CODE"
.org $104F
map_control_0f104f:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
