.setcpu "65816"
.segment "CODE"
.org $8799
map_control_0f8799:
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
