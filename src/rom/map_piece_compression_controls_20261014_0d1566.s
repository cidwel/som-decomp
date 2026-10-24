.setcpu "65816"
.segment "CODE"
.org $1566
map_control_0d1566:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
