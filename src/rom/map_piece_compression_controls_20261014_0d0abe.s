.setcpu "65816"
.segment "CODE"
.org $0ABE
map_control_0d0abe:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
