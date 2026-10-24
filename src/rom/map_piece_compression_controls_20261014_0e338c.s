.setcpu "65816"
.segment "CODE"
.org $338C
map_control_0e338c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
