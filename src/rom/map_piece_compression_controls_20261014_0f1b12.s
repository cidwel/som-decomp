.setcpu "65816"
.segment "CODE"
.org $1B12
map_control_0f1b12:
    .byte $E0 ; previous-row copy escape
    .byte $E7 ; row-distance/count
