.setcpu "65816"
.segment "CODE"
.org $1583
map_control_0d1583:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
