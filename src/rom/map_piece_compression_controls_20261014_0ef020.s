.setcpu "65816"
.segment "CODE"
.org $F020
map_control_0ef020:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
