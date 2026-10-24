.setcpu "65816"
.segment "CODE"
.org $1B12
map_control_0e1b12:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
