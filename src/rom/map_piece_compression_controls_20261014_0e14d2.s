.setcpu "65816"
.segment "CODE"
.org $14D2
map_control_0e14d2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
