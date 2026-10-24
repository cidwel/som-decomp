.setcpu "65816"
.segment "CODE"
.org $F2AA
map_control_0df2aa:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
