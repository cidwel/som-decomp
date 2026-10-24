.setcpu "65816"
.segment "CODE"
.org $B772
map_control_0db772:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
