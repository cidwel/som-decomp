.setcpu "65816"
.segment "CODE"
.org $9341
map_control_0d9341:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
