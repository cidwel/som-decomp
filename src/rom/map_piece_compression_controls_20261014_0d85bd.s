.setcpu "65816"
.segment "CODE"
.org $85BD
map_control_0d85bd:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
