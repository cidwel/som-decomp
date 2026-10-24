.setcpu "65816"
.segment "CODE"
.org $3B65
map_control_0d3b65:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
