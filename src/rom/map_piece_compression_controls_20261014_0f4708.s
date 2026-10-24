.setcpu "65816"
.segment "CODE"
.org $4708
map_control_0f4708:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
