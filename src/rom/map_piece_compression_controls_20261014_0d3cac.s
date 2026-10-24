.setcpu "65816"
.segment "CODE"
.org $3CAC
map_control_0d3cac:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
