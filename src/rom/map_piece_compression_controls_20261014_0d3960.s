.setcpu "65816"
.segment "CODE"
.org $3960
map_control_0d3960:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
