.setcpu "65816"
.segment "CODE"
.org $B0CD
map_control_0eb0cd:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
