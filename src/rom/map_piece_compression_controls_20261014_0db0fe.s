.setcpu "65816"
.segment "CODE"
.org $B0FE
map_control_0db0fe:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
