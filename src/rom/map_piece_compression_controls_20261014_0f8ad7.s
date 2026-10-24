.setcpu "65816"
.segment "CODE"
.org $8AD7
map_control_0f8ad7:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count
