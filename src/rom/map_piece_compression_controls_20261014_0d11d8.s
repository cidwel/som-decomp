.setcpu "65816"
.segment "CODE"
.org $11D8
map_control_0d11d8:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
