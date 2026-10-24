.setcpu "65816"
.segment "CODE"
.org $3444
map_control_0d3444:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
