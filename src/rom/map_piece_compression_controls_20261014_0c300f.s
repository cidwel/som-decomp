.setcpu "65816"
.segment "CODE"
.org $300F
map_control_0c300f:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
