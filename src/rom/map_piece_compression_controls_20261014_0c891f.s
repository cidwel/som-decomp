.setcpu "65816"
.segment "CODE"
.org $891F
map_control_0c891f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
