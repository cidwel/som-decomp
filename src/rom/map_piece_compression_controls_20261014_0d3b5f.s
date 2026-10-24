.setcpu "65816"
.segment "CODE"
.org $3B5F
map_control_0d3b5f:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
