.setcpu "65816"
.segment "CODE"
.org $21BB
map_control_0c21bb:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
