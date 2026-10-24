.setcpu "65816"
.segment "CODE"
.org $B738
map_control_0db738:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
