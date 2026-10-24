.setcpu "65816"
.segment "CODE"
.org $7BB2
map_control_0e7bb2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
