.setcpu "65816"
.segment "CODE"
.org $3509
map_control_0e3509:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
