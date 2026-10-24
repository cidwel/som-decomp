.setcpu "65816"
.segment "CODE"
.org $3419
map_control_0f3419:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
