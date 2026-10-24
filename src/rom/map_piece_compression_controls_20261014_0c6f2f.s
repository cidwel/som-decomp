.setcpu "65816"
.segment "CODE"
.org $6F2F
map_control_0c6f2f:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
