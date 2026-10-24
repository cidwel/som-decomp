.setcpu "65816"
.segment "CODE"
.org $1A65
map_control_0d1a65:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E6 ; previous-row copy count
