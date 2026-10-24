.setcpu "65816"
.segment "CODE"
.org $5776
map_control_0e5776:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
