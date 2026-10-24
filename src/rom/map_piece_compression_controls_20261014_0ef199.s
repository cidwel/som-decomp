.setcpu "65816"
.segment "CODE"
.org $F199
map_control_0ef199:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
