.setcpu "65816"
.segment "CODE"
.org $B0C7
map_control_0db0c7:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
