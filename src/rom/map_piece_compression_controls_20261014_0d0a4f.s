.setcpu "65816"
.segment "CODE"
.org $0A4F
map_control_0d0a4f:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E2 ; previous-row copy count
