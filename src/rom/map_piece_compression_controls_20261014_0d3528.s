.setcpu "65816"
.segment "CODE"
.org $3528
map_control_0d3528:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
