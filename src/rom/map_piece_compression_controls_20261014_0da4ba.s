.setcpu "65816"
.segment "CODE"
.org $A4BA
map_control_0da4ba:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
