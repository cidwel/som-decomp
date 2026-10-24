.setcpu "65816"
.segment "CODE"
.org $488F
map_control_0c488f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
