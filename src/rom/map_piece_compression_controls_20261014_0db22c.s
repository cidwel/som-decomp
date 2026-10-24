.setcpu "65816"
.segment "CODE"
.org $B22C
map_control_0db22c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
