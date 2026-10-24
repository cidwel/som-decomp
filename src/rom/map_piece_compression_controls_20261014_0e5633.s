.setcpu "65816"
.segment "CODE"
.org $5633
map_control_0e5633:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
