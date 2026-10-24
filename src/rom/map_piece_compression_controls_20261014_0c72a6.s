.setcpu "65816"
.segment "CODE"
.org $72A6
map_control_0c72a6:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
