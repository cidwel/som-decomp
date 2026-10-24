.setcpu "65816"
.segment "CODE"
.org $3C1F
map_control_0d3c1f:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
