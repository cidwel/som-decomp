.setcpu "65816"
.segment "CODE"
.org $01E2
map_control_0e01e2:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
