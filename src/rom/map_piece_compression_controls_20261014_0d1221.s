.setcpu "65816"
.segment "CODE"
.org $1221
map_control_0d1221:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
