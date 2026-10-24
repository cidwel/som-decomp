.setcpu "65816"
.segment "CODE"
.org $F5FC
map_control_0ef5fc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
