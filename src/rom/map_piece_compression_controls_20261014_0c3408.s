.setcpu "65816"
.segment "CODE"
.org $3408
map_control_0c3408:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
