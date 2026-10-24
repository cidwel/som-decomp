.setcpu "65816"
.segment "CODE"
.org $6A8F
map_control_0f6a8f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
