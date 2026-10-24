.setcpu "65816"
.segment "CODE"
.org $9257
map_control_0c9257:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
