.setcpu "65816"
.segment "CODE"
.org $1526
map_control_0c1526:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
