.setcpu "65816"
.segment "CODE"
.org $2BD7
map_control_0d2bd7:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
