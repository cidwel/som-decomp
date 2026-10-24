.setcpu "65816"
.segment "CODE"
.org $B0A0
map_control_0db0a0:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
