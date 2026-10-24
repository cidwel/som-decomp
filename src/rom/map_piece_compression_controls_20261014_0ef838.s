.setcpu "65816"
.segment "CODE"
.org $F838
map_control_0ef838:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
