.setcpu "65816"
.segment "CODE"
.org $CADA
map_control_0dcada:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
