.setcpu "65816"
.segment "CODE"
.org $2619
map_control_0c2619:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
