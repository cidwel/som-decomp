.setcpu "65816"
.segment "CODE"
.org $1917
map_control_0f1917:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
