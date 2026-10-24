.setcpu "65816"
.segment "CODE"
.org $B69C
map_control_0eb69c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
