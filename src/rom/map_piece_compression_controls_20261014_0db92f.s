.setcpu "65816"
.segment "CODE"
.org $B92F
map_control_0db92f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
