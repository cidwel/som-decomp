.setcpu "65816"
.segment "CODE"
.org $B681
map_control_0db681:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
