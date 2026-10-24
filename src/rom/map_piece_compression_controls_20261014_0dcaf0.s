.setcpu "65816"
.segment "CODE"
.org $CAF0
map_control_0dcaf0:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
