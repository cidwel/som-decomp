.setcpu "65816"
.segment "CODE"
.org $E7A4
map_control_0de7a4:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
