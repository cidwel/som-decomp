.setcpu "65816"
.segment "CODE"
.org $9F2F
map_control_0d9f2f:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
