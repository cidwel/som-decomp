.setcpu "65816"
.segment "CODE"
.org $1DF9
map_control_0f1df9:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E7 ; previous-row copy count
