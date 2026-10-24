.setcpu "65816"
.segment "CODE"
.org $81EC
map_control_0d81ec:
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
