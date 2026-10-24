.setcpu "65816"
.segment "CODE"
.org $B0D2
map_control_0fb0d2:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
