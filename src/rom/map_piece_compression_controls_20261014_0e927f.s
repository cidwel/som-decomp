.setcpu "65816"
.segment "CODE"
.org $927F
map_control_0e927f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
