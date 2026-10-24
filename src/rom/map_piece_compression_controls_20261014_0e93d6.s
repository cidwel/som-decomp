.setcpu "65816"
.segment "CODE"
.org $93D6
map_control_0e93d6:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
