.setcpu "65816"
.segment "CODE"
.org $1576
map_control_0c1576:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
