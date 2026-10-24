.setcpu "65816"
.segment "CODE"
.org $F408
map_control_0ef408:
    .byte $E0 ; previous-row copy escape
    .byte $BF ; row-distance/count
