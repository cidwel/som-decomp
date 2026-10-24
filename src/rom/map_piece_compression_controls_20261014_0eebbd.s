.setcpu "65816"
.segment "CODE"
.org $EBBD
map_control_0eebbd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
