.setcpu "65816"
.segment "CODE"
.org $3B77
map_control_0d3b77:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
