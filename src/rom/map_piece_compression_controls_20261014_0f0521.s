.setcpu "65816"
.segment "CODE"
.org $0521
map_control_0f0521:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
