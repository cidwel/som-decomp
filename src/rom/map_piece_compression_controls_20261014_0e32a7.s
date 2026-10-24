.setcpu "65816"
.segment "CODE"
.org $32A7
map_control_0e32a7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
