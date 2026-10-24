.setcpu "65816"
.segment "CODE"
.org $9B31
map_control_0d9b31:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
