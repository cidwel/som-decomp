.setcpu "65816"
.segment "CODE"
.org $3503
map_control_0d3503:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
