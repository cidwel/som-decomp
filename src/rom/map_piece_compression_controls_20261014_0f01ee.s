.setcpu "65816"
.segment "CODE"
.org $01EE
map_control_0f01ee:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
