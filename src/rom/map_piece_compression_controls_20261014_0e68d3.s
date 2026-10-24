.setcpu "65816"
.segment "CODE"
.org $68D3
map_control_0e68d3:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
