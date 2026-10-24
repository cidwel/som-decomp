.setcpu "65816"
.segment "CODE"
.org $1482
map_control_0d1482:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
