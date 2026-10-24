.setcpu "65816"
.segment "CODE"
.org $CAC5
map_control_0ecac5:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
