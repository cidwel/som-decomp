.setcpu "65816"
.segment "CODE"
.org $6619
map_control_0d6619:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
