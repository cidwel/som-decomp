.setcpu "65816"
.segment "CODE"
.org $B0E5
map_control_0fb0e5:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
