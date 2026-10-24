.setcpu "65816"
.segment "CODE"
.org $7C6F
map_control_0d7c6f:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
