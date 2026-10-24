.setcpu "65816"
.segment "CODE"
.org $7380
map_control_0c7380:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
