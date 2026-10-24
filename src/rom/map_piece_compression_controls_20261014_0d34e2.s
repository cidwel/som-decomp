.setcpu "65816"
.segment "CODE"
.org $34E2
map_control_0d34e2:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
