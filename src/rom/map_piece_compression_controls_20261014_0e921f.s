.setcpu "65816"
.segment "CODE"
.org $921F
map_control_0e921f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
