.setcpu "65816"
.segment "CODE"
.org $F5F2
map_control_0ef5f2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
