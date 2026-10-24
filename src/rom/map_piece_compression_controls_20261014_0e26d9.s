.setcpu "65816"
.segment "CODE"
.org $26D9
map_control_0e26d9:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
