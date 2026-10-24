.setcpu "65816"
.segment "CODE"
.org $1D3C
map_control_0e1d3c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
