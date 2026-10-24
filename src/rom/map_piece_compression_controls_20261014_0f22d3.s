.setcpu "65816"
.segment "CODE"
.org $22D3
map_control_0f22d3:
    .byte $E9 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
