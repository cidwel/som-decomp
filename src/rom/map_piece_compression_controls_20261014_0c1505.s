.setcpu "65816"
.segment "CODE"
.org $1505
map_control_0c1505:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
