.setcpu "65816"
.segment "CODE"
.org $501E
map_control_0e501e:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
