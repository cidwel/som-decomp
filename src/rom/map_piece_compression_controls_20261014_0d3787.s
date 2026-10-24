.setcpu "65816"
.segment "CODE"
.org $3787
map_control_0d3787:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
