.setcpu "65816"
.segment "CODE"
.org $C866
map_control_0dc866:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
