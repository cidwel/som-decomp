.setcpu "65816"
.segment "CODE"
.org $90D3
map_control_0c90d3:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
