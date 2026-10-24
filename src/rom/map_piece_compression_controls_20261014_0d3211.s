.setcpu "65816"
.segment "CODE"
.org $3211
map_control_0d3211:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
