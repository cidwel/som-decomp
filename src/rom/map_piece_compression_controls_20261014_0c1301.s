.setcpu "65816"
.segment "CODE"
.org $1301
map_control_0c1301:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
