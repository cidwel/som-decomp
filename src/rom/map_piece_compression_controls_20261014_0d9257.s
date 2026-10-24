.setcpu "65816"
.segment "CODE"
.org $9257
map_control_0d9257:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
