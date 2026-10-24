.setcpu "65816"
.segment "CODE"
.org $C27F
map_control_0ec27f:
    .byte $E0 ; previous-row copy escape
    .byte $DE ; row-distance/count
