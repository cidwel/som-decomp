.setcpu "65816"
.segment "CODE"
.org $07CA
map_control_0e07ca:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
