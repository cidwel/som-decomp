.setcpu "65816"
.segment "CODE"
.org $2633
map_control_0c2633:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
