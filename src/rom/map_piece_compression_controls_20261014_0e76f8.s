.setcpu "65816"
.segment "CODE"
.org $76F8
map_control_0e76f8:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
