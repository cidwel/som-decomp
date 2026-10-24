.setcpu "65816"
.segment "CODE"
.org $31A4
map_control_0e31a4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
