.setcpu "65816"
.segment "CODE"
.org $B0CA
map_control_0db0ca:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
