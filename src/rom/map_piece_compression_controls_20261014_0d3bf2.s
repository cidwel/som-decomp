.setcpu "65816"
.segment "CODE"
.org $3BF2
map_control_0d3bf2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
