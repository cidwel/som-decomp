.setcpu "65816"
.segment "CODE"
.org $3B05
map_control_0d3b05:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
