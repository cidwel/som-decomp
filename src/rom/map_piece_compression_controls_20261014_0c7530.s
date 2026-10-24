.setcpu "65816"
.segment "CODE"
.org $7530
map_control_0c7530:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
