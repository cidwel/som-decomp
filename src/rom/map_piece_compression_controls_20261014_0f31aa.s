.setcpu "65816"
.segment "CODE"
.org $31AA
map_control_0f31aa:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
