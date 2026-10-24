.setcpu "65816"
.segment "CODE"
.org $D4D3
map_control_0dd4d3:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
