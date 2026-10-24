.setcpu "65816"
.segment "CODE"
.org $E407
map_control_0fe407:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
