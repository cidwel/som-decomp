.setcpu "65816"
.segment "CODE"
.org $135F
map_control_0d135f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
