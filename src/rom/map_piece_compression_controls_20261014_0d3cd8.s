.setcpu "65816"
.segment "CODE"
.org $3CD8
map_control_0d3cd8:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
