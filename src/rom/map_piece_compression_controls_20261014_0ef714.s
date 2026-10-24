.setcpu "65816"
.segment "CODE"
.org $F714
map_control_0ef714:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
