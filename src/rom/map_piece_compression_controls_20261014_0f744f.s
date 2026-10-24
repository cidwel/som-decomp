.setcpu "65816"
.segment "CODE"
.org $744F
map_control_0f744f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
