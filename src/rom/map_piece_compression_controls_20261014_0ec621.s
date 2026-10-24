.setcpu "65816"
.segment "CODE"
.org $C621
map_control_0ec621:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
