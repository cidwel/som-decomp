.setcpu "65816"
.segment "CODE"
.org $2D3F
map_control_0d2d3f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
