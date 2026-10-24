.setcpu "65816"
.segment "CODE"
.org $1221
map_control_0c1221:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
