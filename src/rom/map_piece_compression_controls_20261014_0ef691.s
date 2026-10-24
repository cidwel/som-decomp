.setcpu "65816"
.segment "CODE"
.org $F691
map_control_0ef691:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
