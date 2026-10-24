.setcpu "65816"
.segment "CODE"
.org $AE5F
map_control_0dae5f:
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
