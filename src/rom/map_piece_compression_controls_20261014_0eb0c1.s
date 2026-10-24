.setcpu "65816"
.segment "CODE"
.org $B0C1
map_control_0eb0c1:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
