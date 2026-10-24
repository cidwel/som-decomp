.setcpu "65816"
.segment "CODE"
.org $242F
map_control_0f242f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
