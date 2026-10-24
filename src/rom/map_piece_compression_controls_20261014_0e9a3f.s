.setcpu "65816"
.segment "CODE"
.org $9A3F
map_control_0e9a3f:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
