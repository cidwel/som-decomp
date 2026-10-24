.setcpu "65816"
.segment "CODE"
.org $F1DC
map_control_0ef1dc:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
