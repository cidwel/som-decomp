.setcpu "65816"
.segment "CODE"
.org $3CC9
map_control_0d3cc9:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
