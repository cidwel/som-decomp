.setcpu "65816"
.segment "CODE"
.org $F533
map_control_0ef533:
    .byte $E0 ; previous-row copy escape
    .byte $B2 ; row-distance/count
