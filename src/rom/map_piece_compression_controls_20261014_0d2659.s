.setcpu "65816"
.segment "CODE"
.org $2659
map_control_0d2659:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
